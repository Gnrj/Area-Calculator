#include "../header_file.h"
#include <math.h>
#include <stdio.h>

#define EPS 1e-6f

typedef double (*Func)(double);

double F_x(Func f1, Func f2, double x, double b) {
    double f_x = f1(x) - f2(x);
    double f_b = f1(b) - f2(b);

    return (x - (f_x * (b - x)) / (f_b - f_x));
}

double root(Func f1, Func f2, double a, double b, double e) {
    double x = a;

    iterations_chords++;

    while (!(fabs(F_x(f1, f2, x, b) - x) < e)) {
        x = F_x(f1, f2, x, b);
        iterations_chords++;
    }

    return x;
}