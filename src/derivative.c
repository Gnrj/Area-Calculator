#include <math.h>
#include <stdio.h>

double sec_der_f1(double x) {
    return exp(-x);
}

double sec_der_f2(double x) {
    return 0.0;
}

double sec_der_f3(double x) {
    return 2 * (1 / (x * x * x));
}

double dif_sec_der_f1_f3(double x) {
    return (sec_der_f1(x) - sec_der_f3(x));
}