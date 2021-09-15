/*The program for finding the root of a non-linear equation using False-Position Method*/
#include<stdio.h>
#include<math.h>

float func(float x)
{
    return x*x*x + 12.1*x*x + 13.1*x + 22.2;                                                     //asking func to return the value of function
    
}

int main(){

	int itr = 1, maxitr;                                                      // declaring iteration and max no. of iterations as a int variable
    float x, a, b, eps, x1;                                                   // declaring the inputs , epsilon value and the average value as a float variable 
    printf("----------------------------------------------------\n\n");
    printf("Finding Root By FALSE-POSITION METHOD\n\n");
    printf("----------------------------------------------------\n\n");
    // initiating a do-while loop to take a feasible input from the user
    do{
        printf("\nEnter the values of a,b, esp, maxitr\n");                   //taking input from user
        scanf("%f %f %f %d", &a, &b, &eps, &maxitr);
 
	}while(func(a)*func(b)>0);

	printf("\niteration\ta\t\t\tb\t\t\tx1\t\t\tf(x1)"); // printing the heading of the table 
	x1= (a*func(b) - b*func(a))/(func(b)-func(a));
	do{
		float f1 = func(x1);                                                  //f1 will represnt the value of func for the value x1
        printf("\n%d\t\t%f\t\t%f", itr, a, b);
        if (func(a) * func(x1) < 0)
        {
            b = x1;                                                           // assigning the value of x1 in place of b for the necessary condition
        }
        else if (func(b) * func(x1) < 0)
        {
            a = x1;                                                           // assigning the value of x1 in place of a for the necessary condition
        }
        printf("\t\t%f\t\t%f", x1,f1);
        x = x1;
        x1= (a*func(b) - b*func(a))/(func(b)-func(a));                        // the value of x1 will be changed here in every iteration 
        itr++;
	} while (itr < maxitr && fabs(x1 - x) > eps);                             //the no. of iteration < the max no. of itertion and the absolute diff > epsilon value 

	
    if (itr < maxitr || fabs(x1 - x) <= eps)
    {
        printf("\nAfter %d iterations ,The approx root with false position method is = %6.6f", itr - 1, x1);          // printing the final result
    }
    else
    {
        printf("\nThe solution does not converge or the iterations are not sufficient");
    }

    printf("\nThe Tolerance is %f", eps);
    return 0;
}