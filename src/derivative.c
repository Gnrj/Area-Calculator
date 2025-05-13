#include <math.h>
#include <stdio.h>

float sec_der_f1(float x) {
    return expf(-x);
}

float sec_der_f2(float x) {
    return 0.0;
}

float sec_der_f3(float x) {
    return 2 * (1 / (x * x * x));
}

float dif_sec_der_f1_f3(float x) {
    return (sec_der_f1(x) - sec_der_f3(x));
}