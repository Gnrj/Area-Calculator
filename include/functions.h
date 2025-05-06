typedef float (*Func)(float);
float f1(float x);
float f2(float x);
float f3(float x);
float root(Func f1, Func f2, float a, float b, float e);