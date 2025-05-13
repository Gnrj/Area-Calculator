#include "../header_file.h"
#include <math.h>
#include <stdio.h>

#define EPS 1e-6f

typedef float (*Func)(float);

float F_x(Func f1, Func f2, float x, float b) {
    float f_x = f1(x) - f2(x);
    float f_b = f1(b) - f2(b);

    return (x - (f_x * (b - x)) / (f_b - f_x));
}

float root(Func f1, Func f2, float a, float b, float e) {
    float x = a;

    iterations_chords++;

    while (!(fabs(F_x(f1, f2, x, b) - x) < e)) {
        x = F_x(f1, f2, x, b);
        iterations_chords++;
    }

    return x;
}