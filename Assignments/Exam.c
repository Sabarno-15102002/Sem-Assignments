#include<stdio.h>
#define size 2 

int main()
{
    float Y[size][size];
    int i,j;
    float A,B,C,D;
    printf("------------------------------------------\n\n");
    printf("Enter the elements :\n");
    printf("------------------------------------------\n\n");
    for(i = 0; i < size ; i++)
    {
        for ( j = 0; j < size; j++)
        {
            printf("Y[%d][%d] =", i,j);
            scanf("%f", &Y[i][j]);
        }
        printf("\n");
    }
    printf("The matrix is :\n");
    for(i = 0; i < size ; i++)
    {
        for ( j = 0; j < size; j++)
        {
            printf("%f\t", Y[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    A = -Y[1][1]/Y[1][0];
    B = -1/Y[1][0];
    C = (Y[0][1]*Y[1][0] - Y[0][0]*Y[1][1])/Y[1][0];
    D = -Y[0][0]/Y[1][0];
    printf("A = %f\n", A);
    printf("B = %f\n", B);
    printf("C = %f\n", C);
    printf("D = %f\n", D);

    return 0;
}