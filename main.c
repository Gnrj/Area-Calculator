#include <getopt.h>
#include <math.h>
#include <stdio.h>

#include "header_file.h"

#define VAREPSILON_1 99e-5f
#define VAREPSILON_2 1e-10f

typedef float (*Func)(float);

enum mode {
    HELP = 1,
    POINTS = 2,
    ITERATIONS = 3,
    ERROR = 4,
    ALL = 5,
};
// Засунуть в интеграл
int rate(float a1, float a2, float a3, float esp2) {

    float dif_3_1 = (a2 - a1) * (a2 - a1) * (a2 - a1);
    float dif_3_2 = (a3 - a2) * (a3 - a2) * (a3 - a2);

    int n1 = (int)sqrtf(dif_3_1 * fabs(sec_der_ft1(a1)) / (12 * esp2)) + 1;
    printf("n1 = %d\n", n1);

    int n2 = (int)sqrtf(dif_3_2 * fabs(sec_der_ft1(a2) - sec_der_ft3(a2)) / (12 * esp2)) + 1;
    printf("n2 = %d\n", n2);

    return (n2 > n1) ? n2 : n1;
}

int iterations = 0;

int separation;

int main(int argc, char* argv[]) {
    enum mode m = flags(argc, argv);

    printf("mode = %d\n", m);

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
    func_iterations[0] = iterations;
    iterations = 0;

    points[1] = root(ft2, ft3, 1.0, 2.0, VAREPSILON_1);
    func_iterations[1] = iterations;
    iterations = 0;

    points[2] = root(ft1, ft2, 1.0, 3.0, VAREPSILON_1);
    func_iterations[2] = iterations;
    iterations = 0;

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

    separation = rate(points[0], points[1], points[2], VAREPSILON_2) * 1000;

    printf("separation = %d\n", separation);

    float square_f1_f2 = integral(dif_ft1_ft2, sec_der_ft1, points[2], points[1], VAREPSILON_2);
    float square_f1_f3 = integral(dif_ft1_ft3, dif_sec_der_ft1_ft3, points[0], points[1], VAREPSILON_2);

    printf("f1-f2 = %f and f1-f3 = %f\n", square_f1_f2, square_f1_f3);

    printf("Square = %f\n", square_f1_f2 + square_f1_f3);

    // printf("Hi\n");

    // printf("rate = %d\n", rate(points[1], points[2], points[0], INACCURACY));

    return 0;
}