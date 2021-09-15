/*Langrange Interpolation method*/
#include<stdio.h>
#include<math.h>

int main(){
	printf("--------------------------------------------------------------------------\n");
	printf("LANGRANGE'S Interpolation Method\n");
	printf("--------------------------------------------------------------------------\n\n\n");
	int p;
	printf("Enter the number of sample values to be entered: ");
	scanf("%d",&p);
	float x_val[p];
	float fx_val[p];
	
	int i=0;
	
	for(i=0;i<p;i++){
		printf("\nEnter x value: ");
		scanf("%f",&(x_val[i]));
		printf("Enter corressponding fx value: ");
		scanf("%f",&(fx_val[i]));
		
	}
	printf("\nEntered x values and corresponding function value are\n\n ");
	printf("-----------------------------------------------\n");
	for(i=0;i<p;i++){
		printf("%f    ",x_val[i]);
	}
	printf("\n");
	for(i=0;i<p;i++){
		printf("%f   ",fx_val[i]);
	}
	printf("\n-----------------------------------------------\n");
	float x;
	
	printf("\nEnter the value at which to be interpolated: ");
	scanf("%f",&x);
	float l=1;
	float ip=0;
	int j=0;
	
	for(i=0;i<p;i++){
		for(j=0;j<p;j++){
			if(i!=j){
				l=l*((x-x_val[j])/(x_val[i]-x_val[j]));
				
			}
			
		}
		
		ip=ip+(l*fx_val[i]);
		l=1;
	}
	
	printf("\n\nThe interpolation at x=%f by Langrange INterpolation method is %f: ",x,ip);	
}
