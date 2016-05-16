#include <equations.h>
#include <math.h>

void root(float (*f)(float), float(*g)(float), float a, float b, float eps, float *x)
{}

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
