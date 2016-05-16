#include <numerical.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-3f

float root(float (*f)(float), float(*g)(float), float a, float b, float eps, int *iters_ptr) {
    int n_iterations = 0;
    if ((f(a) - g(a)) * (f(b) - g(b)) > 0.0f) {
        printf("root needs (f(a) - g(a)) * (f(b) - g(b)) to be < 0!\n");
        exit(1);
    }

    float left = a;
    float right = b;

    while (right - left > eps) {
        n_iterations++;
        float middle = (right + left) / 2.0f;
        if ((f(left) - g(left)) * (f(middle) - g(middle)) < EPS) {
            left = middle;
            break;
        }
        if ((f(left) - g(left)) * (f(middle) - g(middle)) < 0.0f)
            right = middle;
        else
            left = middle;
    }

    if (iters_ptr != NULL)
        *iters_ptr = n_iterations;

    return left;
}

float integral(float (*f)(float), float a, float b, float eps) {
    float prev_result = 0.0f;
    float curr_result = simpsons_formula(f, a, b);
    float curr_gap = b - a / 2;
    int n_iterations = 2;

    while (fabs(curr_result - prev_result) > eps) {
        prev_result = curr_result;
        curr_result = 0.0f;

        for (int i = 0; i < n_iterations; ++i)
            curr_result += simpsons_formula(f, a + i * curr_gap, a + (i + 1) * curr_gap);

        n_iterations++;
        curr_gap = (b - a) / n_iterations;
    }

    return curr_result;
}

float simpsons_formula(float (*f)(float), float a, float b) {
    return (b - a) * (f(a) + 4 * f((a + b) / 2) + f(b)) / 6;
}
