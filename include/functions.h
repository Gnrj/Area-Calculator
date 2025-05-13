typedef float (*Func)(float);

float f1(float x);
float f2(float x);
float f3(float x);

float root(Func f1, Func f2, float a, float b, float e);

float ft1(float x);
float ft2(float x);
float ft3(float x);

float sec_der_ft1(float x);
float sec_der_ft3(float x);

float dif_sec_der_ft1_ft3(float x);

extern int separation;
extern int iterations;

float dif_ft1_ft2(float x);
float dif_ft1_ft3(float x);
float dif_ft2_ft3(float x);

float integral(Func f1, Func sec_dir_f, float a, float b, float esp2);
