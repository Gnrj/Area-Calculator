#include <getopt.h>
#include <stdio.h>

#include "header_file.h"

int main(int argc, char* argv[]) {

    int errors = flags(argc, argv);

    if (errors) {
        return 1;
    }

    float x = f1(-3.2656);

    printf("x = %f\n", x);

    return 0;
}