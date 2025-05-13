#include <math.h>
#include <stdio.h>

float ft1(float x) {
    return expf(-x) + 3;
}

float ft2(float x) {
    return 2 * x - 2;
}

float ft3(float x) {
    return 1 / x;
}

float sec_der_ft1(float x) {
    return expf(-x);
}

float sec_der_ft3(float x) {
    return 2 * (1 / (x * x * x));
}

float dif_sec_der_ft1_ft3(float x) {
    return (sec_der_ft1(x) - sec_der_ft3(x));
}

float dif_ft1_ft2(float x) {
    return (ft1(x) - ft2(x));
}

float dif_ft1_ft3(float x) {
    return (ft1(x) - ft3(x));
}

float dif_ft2_ft3(float x) {
    return (ft2(x) - ft3(x));
}