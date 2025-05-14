#include <math.h>
#include <stdio.h>

double ft1(double x) {
    return exp(-x) + 3;
}

double ft2(double x) {
    return 2 * x - 2;
}

double ft3(double x) {
    return 1 / x;
}

double dif_f1_f2(double x) {
    return (ft1(x) - ft2(x));
}

double dif_f1_f3(double x) {
    return (ft1(x) - ft3(x));
}

double dif_f2_f3(double x) {
    return (ft2(x) - ft3(x));
}