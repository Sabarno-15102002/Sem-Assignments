/*Program to solve a system of linear equations by Gaussian Elimination Method */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int x;
	printf("----------------------------------------------------\n\n");
    printf("Finding solution By GAUSSIAN ELIMINATION METHOD\n\n");
    printf("----------------------------------------------------\n\n");
	printf("Enter The Number of Equations: ");
	scanf("%d", &x);
	float arr[x][(x + 1)];
	int i, j;

	for (i = 0; i < x; i++)
	{
		printf("\nEnter The Coffiecients of %d row: \n", (i + 1));
		for (j = 0; j <= x; j++)
		{
			printf("arr[%d][%d]:", i, j);
			scanf("%f", &arr[i][j]);
		}
	}
	printf("\nSo the respective Equations are: ");
	for (i = 0; i < x; i++)
	{
		printf("\n");
		for (j = 0; j < x; j++)
			printf("%f%c +", arr[i][j], (123 - x + j));
		printf("\b  = %f", arr[i][j]);
	}

	float fac = 0;
	int r = 0;
	int c = 0;
	for (r = 0; r < (x - 1); r++)
	{

		for (i = (r + 1); i < x; i++)
		{
			fac = arr[i][c] / arr[r][c];
			for (j = 0; j <= x; j++)
				arr[i][j] = (arr[i][j] - (fac * arr[r][j]));
		}
		c++;
	}

	c = (x - 1);
	for (r = (x - 1); r > 0; r--)
	{

		for (i = (r - 1); i >= 0; i--)
		{
			fac = arr[i][c] / arr[r][c];
			for (j = 0; j <= x; j++)
				arr[i][j] = (arr[i][j] - (fac * arr[r][j]));
		}
		c--;
	}

	printf("\n\n");
	for (i = 0; i < x; i++)
	{
		printf("\n");
		for (j = 0; j <= x; j++)
			printf("%f ", arr[i][j]);
	}
	printf("\n\n");
	printf("The result by Gauss-Elimination method:");
	float rt;
	for (i = 0; i < x; i++)
	{
		rt = arr[i][x] / arr[i][i];
		printf("\n The solution of %c is: %f", (123 - x + i), rt);
	}
}