#include <getopt.h>
#include <stdio.h>

int flags(int argc, char* argv[]) {
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"points", no_argument, 0, 'p'},
        {"iterations", no_argument, 0, 'i'},
        {"test", no_argument, 0, 't'},
        {0, 0, 0, 0}

    };

    int opt;

    int mode = 0;

    while ((opt = getopt_long(argc, argv, "hpitk:",

                              long_options, NULL)) != -1) {
        switch (opt) {
        case 'h':
            printf("Подсказка:\n");
            return 1;
            break;
        case 'p':
            mode += 2;
            break;
        case 'i':
            mode += 3;
            break;
        case 't':
            printf("Начинаем тестирование\n");
            mode += 4;
            break;
        default:
            printf("Неизвестный флаг: %c\n", opt);

            return 6;
        }
    }

    return mode;
}
