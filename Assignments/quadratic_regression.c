#include<stdio.h>
#include<math.h>

int main(){
	int p;
	printf("Enter the number of observation values for Quadratic Curve Fitting: ");
	scanf("%d",&p);
	
	int i,j=0;
	float arr[7][p];

	int ch=0;
	
	for(i=0;i<p;i++){
		
		printf("\nEnter x value: ");
		scanf("%f",&arr[0][i]);
		printf("\nEnter corresponding fx value: ");
		scanf("%f",&arr[1][i]);
	}
	
	
	for(i=0;i<p;i++){
		arr[2][i]=(arr[0][i]*arr[0][i]);
		arr[3][i]=(arr[0][i]*arr[0][i]*arr[0][i]);
		arr[4][i]=(arr[0][i]*arr[0][i]*arr[0][i]*arr[0][i]);
		arr[5][i]=(arr[0][i]*arr[1][i]);
		arr[6][i]=(arr[0][i]*arr[0][i]*arr[1][i]);
			
	}
	printf("\n\nx     y     x*x	   x*y");
	
	for(i=0;i<p;i++){
		printf("\n");
		for(j=0;j<7;j++)
			printf("%f  ",arr[j][i]);
	}
	float sum[7];
	sum[0],sum[1],sum[2],sum[3],sum[4],sum[5],sum[6]=0.0;
	for(i=0;i<p;i++){
		sum[0]=sum[0]+arr[0][i];
		sum[1]=sum[1]+arr[1][i];
		sum[2]=sum[2]+arr[2][i];
		sum[3]=sum[3]+arr[3][i];
		sum[4]=sum[4]+arr[4][i];
		sum[5]=sum[5]+arr[5][i];
		sum[6]=sum[6]+arr[6][i];
	}
	printf("\n\n\n");
	for(i=0;i<7;i++){
		printf(" %f",sum[i]);
	}
	float gauss[3][4];
	
	gauss[0][0]=p;
	gauss[0][1]=sum[0];
	gauss[0][2]=sum[2];
	gauss[0][3]=sum[1];
	gauss[1][0]=sum[0];
	gauss[1][1]=sum[2];
	gauss[1][2]=sum[3];
	gauss[1][3]=sum[5];
	gauss[2][0]=sum[2];
	gauss[2][1]=sum[3];
	gauss[2][2]=sum[4];
	gauss[2][3]=sum[6];
	int x=3;
 	printf("\n------------------------------------------------------------------------------------------\n\n");
	 float fac=0;
	 int r=0;
	 int c=0;
	 for(r=0;r<(x-1);r++){
	 
	 	for(i=(r+1);i<x;i++){
	 		fac=gauss[i][c]/gauss[r][c];
	 		for(j=0;j<=x;j++)
	 			gauss[i][j]=(gauss[i][j]-(fac*gauss[r][j]));
	 	}
	 	c++;
	}

	c=(x-1);
	 for(r=(x-1);r>0;r--){
	 
	 	for(i=(r-1);i>=0;i--){
	 		fac=gauss[i][c]/gauss[r][c];
	 		for(j=0;j<=x;j++)
	 			gauss[i][j]=(gauss[i][j]-(fac*gauss[r][j]));
	 	}
	 	c--;
	}
	
	printf("------------------------------------------------------------------------------------------");
	for(i=0;i<x;i++){
		printf("\n");
		for(j=0;j<=x;j++)
			printf("%f ",gauss[i][j]);
	}
	
	float a0=gauss[0][3]/gauss[0][0];
	float a1=gauss[1][3]/gauss[1][1];
	float a2=gauss[2][3]/gauss[2][2];
	
	printf("\n\nThe quadratic curve fitting is y= %f + %f x + %f x^2",a0,a1,a2);
}
