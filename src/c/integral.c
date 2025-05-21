#include <math.h>
#include <stdio.h>

#include "../../include/functions.h"

#define EPS 1e-6

typedef double (*Func)(double);

double max_double(double a1, double a2) {
    return (a1 - a2 > EPS) ? a1 : a2;
}

int rate(Func f, double a1, double a2, double esp2) {

    double dif = fabs((a2 - a1) * (a2 - a1) * (a2 - a1));

    int n = (int)sqrt(dif * max_double(fabs(f(a2)), fabs(f(a1))) / (12 * esp2)) + 1;

    return n;
}

int iterations_integral = 0;

double integral(Func f1, Func sec_def_f, double a, double b, double esp2) {

    int n = rate(sec_def_f, a, b, esp2);

    iterations_integral = n;

    double sum = f1(a) + f1(b);

    for (int k = 1; k < n - 1; k++) {
        double x = a + (k * ((b - a) / n));
        sum += 2 * (f1(x));
    }

    sum *= (b - a) / (2 * n);

    return sum + esp2;
}