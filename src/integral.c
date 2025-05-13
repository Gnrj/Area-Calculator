#include <math.h>
#include <stdio.h>

#include "../header_file.h"

#define EPS 1e-6f

typedef float (*Func)(float);

int rate_test(Func f, float a1, float a2, float esp2) {

    float dif = fabs((a2 - a1) * (a2 - a1) * (a2 - a1));

    int n = (int)sqrtf(dif * fabs(f(a2)) / (12 * esp2)) + 1;

    return n;
}

void swap_float(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

float integral(Func f1, Func sec_def_f, float a, float b, float esp2) {

    int n = rate_test(sec_def_f, a, b, esp2);

    if (a - b > EPS) {
        swap_float(&a, &b);
    }

    // int n = separation;
    printf("n = %d\n", n);
    float sum = f1(a) + f1(b);

    for (int k = 1; k < n - 1; k++) {
        float x = a + (k * ((b - a) / n));
        sum += 2 * (f1(x));
    }

    sum *= (b - a) / (2 * n);

    return sum + esp2;
}