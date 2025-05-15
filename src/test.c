#include <math.h>
#include <stdio.h>

#include "../header_file.h"

#define EPS 1e-6

int test_chords(void) {
    printf("Выберите, пожалуйста, две функции: 1) exp(-x)+3; 2) 2x-2; 3) 1/x\n");
    printf("Введите например 1 2: ");

    int ft1, ft2;
    scanf("%d %d", &ft1, &ft2);

    while (ft1 == ft2) {
        printf("Вы выбрали две одиннаковые функции, выберите, пожалуйста, ещё раз: ");
        scanf("%d %d", &ft1, &ft2);
    }

    while (ft1 > 3 || ft2 > 3) {
        printf("Вы выбрали функцию, которой нет, выберите, пожалуйста, ещё раз: ");
        scanf("%d %d", &ft1, &ft2);
    }

    if ((ft1 == ft2) || (ft1 > 3 || ft2 > 3)) {
        printf("Если вы не хотите по-хорошему, то до свидания!\n");
        return 0;
    }

    printf("Выберите пожалуйста интервал, например 1.2 2.7: ");

    double a1, a2;
    scanf("%lf %lf", &a1, &a2);

    while (a1 - a2 > EPS || fabs(a1 - a2) <= EPS) {
        printf("У вас некорректно указан интервал, выберите его ещё раз пожалуйста: ");
        scanf("%lf %lf", &a1, &a2);
    }

    printf("Введите погрешность: ");
    double esp;
    scanf("%lf", &esp);

    while (esp < 0.0) {
        printf("У вас отрицательная погрешность, введите её пожалуйста снова: ");
        scanf("%lf", &esp);
    }

    double x = 0;

    if (ft1 == 1) {
        switch (ft2) {
        case 2:
            x = root(f1, f2, a1, a2, esp);
            break;
        case 3:
            x = root(f1, f3, a1, a2, esp);
            break;
        default:
            x = NAN;
            break;
        }
    }

    if (ft1 == 2) {
        switch (ft2) {
        case 1:
            x = root(f1, f2, a1, a2, esp);
            break;
        case 3:
            x = root(f2, f3, a1, a2, esp);
            break;
        default:
            x = NAN;
            break;
        }
    }

    if (ft1 == 3) {
        switch (ft2) {
        case 1:
            x = root(f1, f3, a1, a2, esp);
            break;
        case 2:
            x = root(f2, f3, a1, a2, esp);
            break;
        default:
            x = NAN;
            break;
        }
    }

    if (!isnan(x)) {
        printf("Точка пересечения заданных функций равна: %lf\n", x);
        printf("Было затрачено следующее количество итераций: %d.\n", iterations_chords);
    }

    return 0;
}

int test_integral(void) {
    printf("Выберите, пожалуйста, интеграл какой кривой вы хотите посчитать: 1) exp(-x)+3 - 1/x; 2) exp(-x)-2x+5\n");
    printf("Введите 1 или 2: ");

    int mode;
    scanf("%d", &mode);

    printf("Выберите, пожалуйста, интервал, например 1.2 2.7: ");

    double a1, a2;
    scanf("%lf %lf", &a1, &a2);

    while (a1 - a2 > EPS || fabs(a1 - a2) <= EPS) {
        printf("У вас некорректно указан интервал, выберите его ещё раз пожалуйста: ");
        scanf("%lf %lf", &a1, &a2);
    }

    printf("Введите погрешность: ");
    double esp;
    scanf("%lf", &esp);

    while (esp < 0.0) {
        printf("У вас отрицательная погрешность, введите её, пожалуйста, снова: ");
        scanf("%lf", &esp);
    }

    double x;

    if (mode == 1) {
        if (a1 < 0.0 && a2 > 0.0) {
            printf("Функция 1/x не определена на данном промежутке.\n");
            return 1;
        }

        x = integral(dif_f1_f3, dif_sec_der_f1_f3, a1, a2, esp);
    } else {
        x = integral(dif_f1_f2, sec_der_f1, a1, a2, esp);
    }

    printf("Исходный интеграл равен: %lf\n", x);
    printf("Было затрачено следующее количество итераций: %d.\n", iterations_integral);

    return 0;
}

int test(void) {
    printf("Пожалуйста введите:\n1, если хотите протестировать функцию нахождения точки пересечения;\n");
    printf("2, если хотите протестировать подсчёт интеграла;\n");
    printf("Введите желаемое вами значение: ");

    int mode;
    scanf("%d", &mode);

    int errors = 1;

    switch (mode) {
    case 1:
        errors = test_chords();
        break;
    case 2:
        errors = test_integral();
    default:
        printf("Вы выбрали не существующий режим.\n");
        break;
    }

    return errors;
}