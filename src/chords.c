#include "../header_file.h"
#include <math.h>
#include <stdio.h>

#define EPS 1e-10

typedef double (*Func)(double);

double F_x(Func f1, Func f2, double x, double a) {
    double f_x = f1(x) - f2(x);
    double f_a = f1(a) - f2(a);

    return (x - (f_x * (a - x)) / (f_a - f_x));
}

double root(Func f1, Func f2, double a, double b, double e) {
    double x = b; // a

    iterations_chords++;

    if (F_x(f1, f2, x, a) < a - EPS || F_x(f1, f2, x, a) > b - EPS) {
        printf("На данном отрезке нет точки пересечения либо одна из функций не определена.\n");

        return NAN;
    }

    if (isnan(F_x(f1, f2, x, a))) {
        printf("На данном отрезке одна из функций не опередела.\n");

        return NAN;
    }

    while (!(fabs(F_x(f1, f2, x, a) - x) < e)) { // F_x(f1, f2, x, b)
        x = F_x(f1, f2, x, a);                   // F_x(f1, f2, x, b)

        if (x < a - EPS || x > b - EPS) {
            printf("На данном отрезке нет точки пересечения либо одна из функций не определена.\n");

            return NAN;
        }

        if (isnan(x)) {
            printf("На данном отрезке одна из функций не опередела.\n");

            return NAN;
        }

        iterations_chords++;
    }

    return x;
}