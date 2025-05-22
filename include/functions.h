typedef double (*Func)(double);

double f1(double x);
double f2(double x);
double f3(double x);

double root(Func f1, Func f2, double a, double b, double esp);
double bisection(Func f1, Func f2, double a, double b, double esp);

double sec_der_f1(double x);
double sec_der_f2(double x);
double sec_der_f3(double x);

double dif_sec_der_f1_f3(double x);

extern int iterations_chords;
extern int iterations_integral;

double dif_f1_f2(double x);
double dif_f1_f3(double x);
double dif_f2_f3(double x);

double integral(Func f1, Func sec_dir_f, double a, double b, double esp2);
