#include <math.h>
#include <stdio.h>

#include "../../include/functions.h"

#define EPS 1e-10

typedef double (*Func)(double);

double f_dif(Func f1, Func f2, double x) {
    return f1(x)- f2(x); 
}

double F_x(Func f1, Func f2, double x, double a) {
    double f_x = f1(x) - f2(x);
    double f_a = f1(a) - f2(a);

    return (x - (f_x * (a - x)) / (f_a - f_x));
}

double root(Func f1, Func f2, double a, double b, double esp) {
    double x = b; // a

    iterations_chords++;

    if (F_x(f1, f2, x, a) < a - EPS || F_x(f1, f2, x, a) > b - EPS) {
        printf("На данном отрезке нет точки пересечения либо одна из функций не определена.\n");

        return NAN;
    }

    if (isnan(F_x(f1, f2, x, a))) {
        printf("На данном отрезке одна из функций не опередела.\n");

        return NAN;
    }

    while (!(fabs(F_x(f1, f2, x, a) - x) < esp)) { // F_x(f1, f2, x, b)
        x = F_x(f1, f2, x, a);                   // F_x(f1, f2, x, b)

        if (x < a - EPS || x > b - EPS) {
            printf("На данном отрезке нет точки пересечения либо одна из функций не определена.\n");

            return NAN;
        }

        if (isnan(x)) {
            printf("На данном отрезке одна из функций не опередела.\n");

            return NAN;
        }

        iterations_chords++;
    }

    return x;
}

double bisection(Func f1, Func f2, double a, double b, double esp) {
    double c;
    
    if (f_dif(f1, f2, a) * f_dif(f1, f2, b) >= 0) {
        printf("На данном отрезке нет корня.\n");
        return NAN;
    }
    
    while ((b - a) >= esp) {
        iterations_chords++;
        
        c = (a + b) / 2;
        
        if (fabs(f_dif(f1, f2, c)) < esp) {
            break;
        } else if (f_dif(f1, f2, c) * f_dif(f1, f2, a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    return (a + b) / 2;
}