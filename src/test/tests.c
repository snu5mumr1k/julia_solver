#include <functions.h>
#include <math.h>
#include <stdio.h>

const float EPS = 1e-3f;
const int TESTS_COUNT = 3;

int test_f1() {
    return fabs(f1(0.5) - 3 * (0.5 / 1.5 + 1)) < EPS;
}

int test_f2() {
    return fabs(f2(0.5) - (2.5 * 0.5 - 9.5)) < EPS;
}

int test_f3() {
    return fabs(f3(0.5) - (5 / 0.5)) < EPS;
}

int run_tests(int n, int (*tests[n])()) {
    for (int i = 0; i < n; ++i)
        if (!tests[i]())
            return 0;

    return 1;
}

int main(void) {
    int (*tests[])() = {test_f1, test_f2, test_f3};
    if (run_tests(TESTS_COUNT, tests))
        printf("Tests passed!");
    else
        printf("Test check failed!");

    return 0;
}
