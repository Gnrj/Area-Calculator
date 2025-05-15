#include <getopt.h>
#include <math.h>
#include <stdio.h>

#include "header_file.h"

#define VAREPSILON_1 1e-10 // 0.001 - (1e-10)
#define VAREPSILON_2 1e-10

enum mode {
    HELP = 1,
    POINTS = 2,
    ITERATIONS = 3,
    TEST = 4,
    ALL = 5,
    ERROR = 6,
};

int iterations_chords = 0;

int main(int argc, char* argv[]) {
    enum mode m = flags(argc, argv);

    if (m == ERROR) {
        return 0;
    }

    if (m == TEST) {
        return test();
    }

    if (m == HELP) {
        printf("Программа поддерживает следующие ключи:\n");
        printf("-p или --points: выводит точки пересечения;\n");
        printf("-i или --iterations: выводит количество итераций при поиске точек;\n");
        printf("-t или --test: запускает тестовый режим;\n");
        printf("Программа также поддерживает объединенный флаг -pi.");
        return 0;
    }

    double points[3];
    int func_iterations[3];

    points[0] = root(f1, f3, 0.1, 0.5, VAREPSILON_1); // 0.1, 0.5, если меньше a1 либо a2, то гг
    func_iterations[0] = iterations_chords;
    iterations_chords = 0;

    points[1] = root(f2, f3, 1.0, 2.0, VAREPSILON_1); // 1.0 2.0, если меньше a1, то гг
    func_iterations[1] = iterations_chords;
    iterations_chords = 0;

    points[2] = root(f1, f2, 1.0, 3.0, VAREPSILON_1); // 1.0, 3.0, если меньше a1, то гг
    func_iterations[2] = iterations_chords;
    iterations_chords = 0;

    if (m == POINTS || m == ALL) {
        printf("Пересечение exp(-x)+3 и 2x-2: x = %lf, y = %lf\n", points[2], f1(points[2]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 2x-2: %d\n\n", func_iterations[2]);
        }

        printf("Пересечение exp(-x)+3 и 1/x: x = %lf, y = %lf\n", points[0], f1(points[0]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 1/x: %d\n\n", func_iterations[0]);
        }

        printf("Пересечение 2x-2 и 1/x: x = %lf, y = %lf\n", points[1], f2(points[1]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых 2x-2 и 1/x: %d\n\n", func_iterations[1]);
        }
    }

    if (m == ITERATIONS) {
        printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 2x-2: %d\n", func_iterations[2]);
        printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 1/x: %d\n", func_iterations[0]);
        printf("Количество итераций при подсчёте точек пересечения кривых 2x-2 и 1/x: %d\n", func_iterations[1]);
    }

    double square_f1_f2 = integral(dif_f1_f2, sec_der_f1, points[2], points[1], VAREPSILON_2);
    double square_f1_f3 = integral(dif_f1_f3, dif_sec_der_f1_f3, points[0], points[1], VAREPSILON_2);

    printf("Square = %lf\n", square_f1_f2 + square_f1_f3);

    return 0;
}