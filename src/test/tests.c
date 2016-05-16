#include <equations.h>
#include <functions.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846264338327
#define EPS 1e-3f

static int test_f1();
static int test_f2();
static int test_f3();
static int test_integral();
static int test_root();
static int run_tests(int n, int (*tests[n])());

static float foo1(float x);
static float foo2(float x);

int main(void) {
    int n_tests = 5;
    int (*tests[])() = {test_f1, test_f2, test_f3, test_root, test_integral};
    char *func_names[] = {"f1", "f2", "f3", "root", "integral"};

    int result = run_tests(n_tests, tests);

    if (!result)
        printf("All tests passed!");
    else
        printf("Tests check failed while testing function %s !", func_names[result - 1]);

    return 0;
}

int test_f1() {
    return fabs(f1(0.5) - 3 * (0.5 / 1.5 + 1)) < EPS;
}

int test_f2() {
    return fabs(f2(0.5) - (2.5 * 0.5 - 9.5)) < EPS;
}

int test_f3() {
    return fabs(f3(0.5) - (5 / 0.5)) < EPS;
}

float foo1(float x) {
    return x;
}

float foo2(float x) {
    return sinf(x);
}

int test_root() {
    return fabs(root(foo1, foo2, -0.5f, 0.5f, EPS, NULL)) < EPS;
}

int test_integral() {
    return fabs(integral(foo2, 0.0f, 2 * M_PI, EPS)) < EPS;
}

int run_tests(int n, int (*tests[n])()) {
    for (int i = 0; i < n; ++i)
        if (!tests[i]())
            return i + 1;

    return 0;
}
