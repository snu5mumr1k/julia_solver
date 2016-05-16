extern void root(float (*f)(float), float(*g)(float), float a, float b, float eps, float *x);
extern float integral(float (*f)(float), float a, float b, float eps);

static float simpsons_formula(float (*f)(float), float a, float b);
