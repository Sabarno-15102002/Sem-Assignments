/* Program: Finding real roots of nonlinear equation using Newton Raphson Method */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
//#define    f(x)    exp(x)-3*x
#define f(x) 4 * sin(x) - exp(x)

/* Defining derivative of g(x).
   As you change f(x), change this function also. */
//#define   g(x)   exp(x)- 3
#define g(x) 4 * cos(x) - exp(x)
void main()
{
	float x0, x1, f0, f1, g0, e;
	int step = 1, N;

	printf("----------------------------------------------------\n\n");
    printf("Finding Root By NEWTON-RAPHSON METHOD\n\n");
    printf("----------------------------------------------------\n\n");
	/* Inputs */
	printf("\nEnter initial guess:\n");
	scanf("%f", &x0);
	printf("Enter tolerable error:\n");
	scanf("%f", &e);
	printf("Enter maximum iteration:\n");
	scanf("%d", &N);
	/* Implementing Newton Raphson Method */
	printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do
	{
		g0 = g(x0);
		f0 = f(x0);
		if (g0 == 0.0)
		{
			printf("Mathematical Error.");
			exit(0);
		}

		x1 = x0 - f0 / g0;

		printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
		x0 = x1;

		step = step + 1;

		if (step > N)
		{
			printf("Not Convergent.");
			exit(0);
		}

		f1 = f(x1);

	} while (fabs(f1) > e);

	printf("\nRoot by Newton-Raphson method after %d iterations is: %f", step - 1, x1);
	getch();
}