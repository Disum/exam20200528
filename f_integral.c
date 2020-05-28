#include <math.h>
#include "f_integral.h"

static int count = 0;

int get_count_f_integral(void)
{
	return count;
}

double f_integral(double x, double t)
{
	++count;

	return sqrt(1 + x*t*t);
}
