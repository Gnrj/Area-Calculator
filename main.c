#include <getopt.h>
#include <stdio.h>

#include "header_file.h"

int main(int argc, char* argv[]) {

    int mode = flags(argc, argv);

    printf("%d\n", mode);

    if (mode == 0) {
        return 0;
    }

    float x = root(f1, f2, 1.0, 3.0, 0.001);

    // float x = root(f1, f3, 0.01, 0.5, 0.001);

    // float x = root(f2, f3, 1.0, 2.0, 0.001);

    printf("x = %f\n", x);

    return 0;
}