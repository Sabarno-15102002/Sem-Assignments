/***********************************************
****EULER METHOD FOR DIFFERENTIAL EQUATIONS*****
***********************************************/
#include<stdio.h>
#include<math.h>
/*Define the RHS of the first order differential equation here(Ex: dy/dx=f(x,y))  */
double f(double x, double y){
    return 2*x*x - y; 
}
int main(){
    int i;
    double y,xi,yi,xf,h;
    printf("---------------------------------------------------------------------\n");
    printf("EULER'S METHOD\n\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("Enter the initial condition for y: ");
    scanf("%lf",&yi);
    printf("Enter the initial condition for x: ");
    scanf("%lf",&xi);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf",&xf);
    printf("Enter the step-width h: ");
    scanf("%lf",&h);
    printf("x\t\ty\t\ty'\t\thy'\t\ty+hy'\n");
    printf("__________________________________________________________________________\n");
    //Begin Euler Routine
    while(xi<xf){
        y=yi+h*f(xi,yi);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\n",xi,yi,f(xi,yi),h*f(xi,yi),y);
        yi=y;
        xi=xi+h;
    }
    printf("%lf\t%lf\n",xi,yi);
    printf("__________________________________________________________________________\n");
    printf("The value of y is %.4lf\n\n",y);
    return 0;
}