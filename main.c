#include <stdio.h>
#include <time.h>
#include <math.h>
#include "solve.h"
#include "f.h"
#define ERROR_READ (-1)
#define H (1e-3)
#define N (1e5)

int main(int argc, char **argv)
{
	double a = 0, eps, x, b = H, f_a, f_b;
	int it, i;
	clock_t time_beg;

	if( argc!=2 )
	{
		fprintf(stderr, "Error! Usage: %s eps\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%lf", &eps)!=1 || eps<=0 )
	{
		fprintf(stderr, "Error! Can not read eps>0!\n");
		return ERROR_READ;
	}

	time_beg = clock();
	f_a = f(a, eps);
	f_b = f(b, eps);
	for( i = 0; i<N; i++, a += H, b += H )
	{
		if( f_a*f_b<=0 )
		{
			it = solve(&f, a, b, eps, &x);
			if( it!=SOLVE_NOT_FOUND )
				printf("x = %.16e\t|f(x)| = %.16e\tit = %d\n", x, fabs(f(x, eps)), it);
		}

		f_a = f_b;
		f_b = f(b, eps);
	}
	printf("Time: %.2lf seconds\n", (double)(clock() - time_beg)/CLOCKS_PER_SEC);

	return 0;
}
