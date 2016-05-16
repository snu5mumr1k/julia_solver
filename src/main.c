#include <equations.h>
#include <functions.h>
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

int main(int argc, char **argv) {
    int mode = parse_args(argc, argv);

    if (mode & PRINT_HELP) {
        printf("%s", help);
        return 0;
    }



    return 0;
}
