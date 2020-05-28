#include <math.h>
#include "f.h"
#include "integrate.h"
#include "f_integral.h"

static int count = 0;

double f(double x, double eps)
{
	double integral;

	count++;

	integrate(&f_integral, x, 0, x, eps, &integral);
	return integral - x*x*x;
}

int get_count_f(void)
{
	return count;
}
