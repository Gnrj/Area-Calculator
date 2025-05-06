#include <getopt.h>
#include <stdio.h>

#include "header_file.h"

#define INACCURACY 0.001

enum mode {
    HELP = 1,
    POINTS = 2,
    ITERATIONS = 3,
    ERROR = 4,
    ALL = 5,
};

int main(int argc, char* argv[]) {
    enum mode m = flags(argc, argv);

    printf("mode = %d\n", m);

    if (m == ERROR) {
        return 0;
    }

    if (m == HELP) {
        printf("Программа поддерживает следующие ключи:\n");
        printf("-p или --pointers: выводит точки пересечения\n");
        printf("-i или --iterations: выводит количество итераций при поиске точек\n");
        printf("Программа также поддерживает объединенный флаг -pi");
        return 0;
    }

    float points[3];

    points[0] = root(f1, f2, 1.0, 3.0, INACCURACY);
    points[1] = root(f1, f3, 0.01, 0.5, INACCURACY);
    points[2] = root(f2, f3, 1.0, 2.0, INACCURACY);

    if (m == POINTS || m == ALL) {
        printf("Пересечение exp(-x)+3 и 2x-2: %f\n", points[0]);
        printf("Пересечение exp(-x)+3 и 1/x: %f\n", points[1]);
        printf("Пересечение 2x-2 и 1/x: %f\n", points[2]);
    }

    printf("Hi\n");

    return 0;
}