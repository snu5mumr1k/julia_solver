extern float root(float (*f)(float), float(*g)(float), float a, float b, float eps, int *iters_ptr);
extern float integral(float (*f)(float), float a, float b, float eps, int *iters_ptr);

static float simpsons_formula(float (*f)(float), float a, float b);
