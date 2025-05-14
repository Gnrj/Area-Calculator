#include <math.h>
#include <stdio.h>

#include "../header_file.h"

#define EPS 1e-6f

typedef double (*Func)(double);

int rate(Func f, double a1, double a2, double esp2) {

    double dif = fabs((a2 - a1) * (a2 - a1) * (a2 - a1));

    int n = (int)sqrt(dif * fabs(f(a2)) / (12 * esp2)) + 1;

    return n;
}

void swap_double(double* a, double* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

double integral(Func f1, Func sec_def_f, double a, double b, double esp2) {

    int n = rate(sec_def_f, a, b, esp2);

    if (a - b > EPS) {
        swap_double(&a, &b);
    }

    double sum = f1(a) + f1(b);

    for (int k = 1; k < n - 1; k++) {
        double x = a + (k * ((b - a) / n));
        sum += 2 * (f1(x));
    }

    sum *= (b - a) / (2 * n);

    return sum + esp2;
}