#include<stdio.h>
#include<math.h>
float function (float);
int main(){
	printf("----------------------------------------------------------------------------------");
	printf("\nSimpson's rule");
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
	float in=arr[1][0]+arr[1][n];
	
	for(i=1;i<=n-1;i++){
		if(i%2!=0)
			in=in+4*arr[1][i];
		else
			in=in+2*arr[1][i];	
	}
	in=(in*inv)/3;
	printf("The Intergration value of function f(x) from %f to %f by Simpson's rule is = %f ",arr[0][0],arr[0][n],in);
}

float function (float f){
	float pi= 22/7;
	return f*f*f + f*f + 2*f;
}
