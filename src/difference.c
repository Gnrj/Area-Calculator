#include <math.h>
#include <stdio.h>

#include "../header_file.h"

double dif_f1_f2(double x) {
    return (f1(x) - f2(x));
}

double dif_f1_f3(double x) {
    return (f1(x) - f3(x));
}

double dif_f2_f3(double x) {
    return (f2(x) - f3(x));
}