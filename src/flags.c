#include <getopt.h>
#include <stdio.h>

int flags(int argc, char* argv[]) {
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"verbose", required_argument, 0, 'v'},
        {0, 0, 0, 0}

    };

    int opt;

    while ((opt = getopt_long(argc, argv, "hv:",

                              long_options, NULL)) != -1) {
        switch (opt) {
        case 'h':
            printf("Help menu\n");

            break;
        case 'v':
            printf("Verbose level: %s\n", optarg);

            break;
        default:
            printf("Unknown option: %c\n", opt);

            return 1;
        }
    }

    return 0;
}
