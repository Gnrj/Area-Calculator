#include <getopt.h>
#include <math.h>
#include <stdio.h>

#include "header_file.h"

#define VAREPSILON_1 99e-8f
#define VAREPSILON_2 1e-10f

typedef float (*Func)(float);

enum mode {
    HELP = 1,
    POINTS = 2,
    ITERATIONS = 3,
    ERROR = 4,
    ALL = 5,
};

int iterations_chords = 0;

int main(int argc, char* argv[]) {
    enum mode m = flags(argc, argv);

    if (m == ERROR) {
        return 0;
    }

    if (m == HELP) {
        printf("Программа поддерживает следующие ключи:\n");
        printf("-p или --points: выводит точки пересечения\n");
        printf("-i или --iterations: выводит количество итераций при поиске точек\n");
        printf("Программа также поддерживает объединенный флаг -pi");
        return 0;
    }

    float points[3];
    int func_iterations[3];

    points[0] = root(ft1, ft3, 0.01, 0.5, VAREPSILON_1);
    func_iterations[0] = iterations_chords;
    iterations_chords = 0;

    points[1] = root(ft2, ft3, 1.0, 2.0, VAREPSILON_1);
    func_iterations[1] = iterations_chords;
    iterations_chords = 0;

    points[2] = root(ft1, ft2, 1.0, 3.0, VAREPSILON_1);
    func_iterations[2] = iterations_chords;
    iterations_chords = 0;

    if (m == POINTS || m == ALL) {
        printf("Пересечение exp(-x)+3 и 2x-2: x = %f, y = %f\n", points[2], ft1(points[2]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 2x-2: %d\n\n", func_iterations[2]);
        }

        printf("Пересечение exp(-x)+3 и 1/x: x = %f, y = %f\n", points[0], ft1(points[0]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 1/x: %d\n\n", func_iterations[0]);
        }

        printf("Пересечение 2x-2 и 1/x: x = %f, y = %f\n", points[1], ft2(points[1]));

        if (m == ALL) {
            printf("Количество итераций при подсчёте точек пересечения кривых 2x-2 и 1/x: %d\n\n", func_iterations[1]);
        }
    }

    if (m == ITERATIONS) {
        printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 2x-2: %d\n", func_iterations[2]);
        printf("Количество итераций при подсчёте точек пересечения кривых exp(-x)+3 и 1/x: %d\n", func_iterations[0]);
        printf("Количество итераций при подсчёте точек пересечения кривых 2x-2 и 1/x: %d\n", func_iterations[1]);
    }

    float square_f1_f2 = integral(dif_f1_f2, sec_der_f1, points[2], points[1], VAREPSILON_2);
    float square_f1_f3 = integral(dif_f1_f3, dif_sec_der_f1_f3, points[0], points[1], VAREPSILON_2);

    printf("Square = %f\n", square_f1_f2 + square_f1_f3);

    return 0;
}