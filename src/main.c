#include <functions.h>
#include <numerical.h>
#include <stdio.h>
#include <string.h>

enum MODE {
    PRINT_HELP = 1 << 0,
    PRINT_ROOTS = 1 << 1,
    PRINT_ITERATIONS = 1 << 2,
};

char *help = "usage: ./bin/main [--help] [options...]\n\n  -r, --print-roots      print intersection points for curves\n  -i, --print-iters      print number of iterations for each point\n\n  -h, --help             print this help info and exit\n\nTo run tests call: ./bin/tests\n";

int parse_args(int argc, char **argv) {
    int mode = 0;
    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "-h"))
            return PRINT_HELP;
        if (!strcmp(argv[i], "--help"))
            return PRINT_HELP;

        if (!strcmp(argv[i], "-r"))
            mode |= PRINT_ROOTS;
        if (!strcmp(argv[i], "--print-roots"))
            mode |= PRINT_ROOTS;
        if (!strcmp(argv[i], "-i"))
            mode |= PRINT_ITERATIONS;
        if (!strcmp(argv[i], "--print-iters"))
            mode |= PRINT_ITERATIONS;
    }
    return mode;
}

void run_methods(int mode) {
    float eps1 = 0.0001f;
    int iterations_12 = 0;
    float x_12 = root(f1, f2, 4.5f, 5.5f, eps1, &iterations_12);
    int iterations_13 = 0;
    float x_13 = root(f1, f3, 1.0f, 2.0f, eps1, &iterations_13);
    int iterations_23 = 0;
    float x_23 = root(f2, f3, 4.0f, 5.0f, eps1, &iterations_23);

    float eps2 = 0.0001f;
    float area = integral(f1, x_13, x_12, eps2) 
                 - integral(f3, x_13, x_23, eps2)
                 - integral(f2, x_23, x_12, eps2);

    if (mode & PRINT_ROOTS) {
        printf("Intersection abscissa for f1 and f2 is %.3f\n", x_12);
        printf("Intersection abscissa for f1 and f3 is %.3f\n", x_13);
        printf("Intersection abscissa for f2 and f3 is %.3f\n\n", x_23);
    }
    if (mode & PRINT_ITERATIONS) {
        printf("Intersection between f1 and f2 computed in %d iterations\n", iterations_12);
        printf("Intersection between f1 and f3 computed in %d iterations\n", iterations_13);
        printf("Intersection between f2 and f3 computed in %d iterations\n\n", iterations_23);
    }
    printf("Area square is %.3f\n", area);

}

int main(int argc, char **argv) {
    int mode = parse_args(argc, argv);

    if (mode & PRINT_HELP) {
        printf("%s", help);
        return 0;
    }

    run_methods(mode);

    return 0;
}
