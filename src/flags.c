#include <getopt.h>
#include <stdio.h>

int flags(int argc, char* argv[]) {
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"points", no_argument, 0, 'p'},
        {"count", no_argument, 0, 'c'},
        {0, 0, 0, 0}

    };

    int opt;

    int mode = 0;

    while ((opt = getopt_long(argc, argv, "hpck:",

                              long_options, NULL)) != -1) {
        switch (opt) {
        case 'h':
            printf("Help menu\n");
            return 0;
            break;
        case 'p':
            printf("Verbose level:\n");
            ++mode;
            break;
        case 'c':
            printf("DJhfjshfjs\n");
            mode += 2;
            break;
        default:
            printf("Unknown option: %c\n", opt);

            return 1;
        }
    }

    return mode;
}
