#include <stdio.h>
#include <math.h>

int main()
{
	int p;
	printf("Enter the number of observation values for Linear Curve Fitting: ");
	scanf("%d", &p);

	int i, j = 0;
	float arr[4][p];

	int ch = 0;

	for (i = 0; i < p; i++)
	{

		printf("\nEnter x value: ");
		scanf("%f", &arr[0][i]);
		printf("\nEnter corresponding fx value: ");
		scanf("%f", &arr[1][i]);
	}

	for (i = 0; i < p; i++)
	{
		arr[2][i] = (arr[0][i] * arr[0][i]);
		arr[3][i] = (arr[0][i] * arr[1][i]);
	}
	printf("\n\nx            y         x*x           x*y");

	for (i = 0; i < p; i++)
	{
		printf("\n");
		for (j = 0; j < 4; j++)
			printf("%f  ", arr[j][i]);
	}

	float sum[4];
	sum[0], sum[1], sum[2], sum[3] = 0.0;
	for (i = 0; i < p; i++)
	{
		sum[0] = sum[0] + arr[0][i];
		sum[1] = sum[1] + arr[1][i];
		sum[2] = sum[2] + arr[2][i];
		sum[3] = sum[3] + arr[3][i];
	}

	float a0, a1 = 0;

	a0 = ((sum[2] * sum[1]) - (sum[0] * sum[3])) / (p * sum[2] - (sum[0] * sum[0]));
	a1 = ((p * sum[3]) - (sum[0] * sum[1])) / (p * sum[2] - (sum[0] * sum[0]));

	printf("\n\n\nThe Linear curve plotted Equation of the form (y=a0=+a1*x)  is y=%f+%fx ", a0, a1);
}
