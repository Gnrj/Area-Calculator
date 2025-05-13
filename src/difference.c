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

float dif_f1_f2(float x) {
    return (ft1(x) - ft2(x));
}

float dif_f1_f3(float x) {
    return (ft1(x) - ft3(x));
}

float dif_f2_f3(float x) {
    return (ft2(x) - ft3(x));
}