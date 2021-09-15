#include<stdio.h>
#include<math.h>

float function(float);
int main(){
	printf("----------------------------------------------------------------------------------");
	printf("\nTrapezoidal Rule of Integration");
	printf("\n----------------------------------------------------------------------------------");
	int n;
	printf("\n\n\nEnter the number of intervals: ");
	scanf("%d",&n);
	float l1,l2;
	printf("Enter the lower limit :");
	scanf("%f",&l1);
	printf("Enter the upper limit :");
	scanf("%f",&l2);
	float arr[2][n+1];
	int i,j=0;
	float c=l1;
	float inv=(l2-l1)/n;
	for(i=0;i<=n;i++){
		arr[0][i]=c;
		arr[1][i]=function(c);
		c=c+inv;
	}
	
	float in=0.0;
	for(i=0;i<(n);i++){
		in=in+(inv*(arr[1][i]+arr[1][i+1])/2.0);
		
	}
	
	printf("Intergal value over %f to %f by Trapezoidal rule of integration is = %f",arr[0][0],arr[0][n],in);
	
}
float function(float f){
	return 1/(1+(f*f));
}
