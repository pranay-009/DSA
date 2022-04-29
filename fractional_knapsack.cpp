#include <stdio.h>
#include <stdlib.h>

void print(float [],int);
void sort(float[],float[],float[],int);
float max_profit(float[],float[],float[],int ,float );

 int main(){
 	
 	int i,j,k,n,t,p;
 	float w,max;
 	printf("Enter the size of array?");
 	scanf("%d",&n);
 	float weight[n];
 	float price[n];
 	float ratio[n];
 	for(i=0;i<n;i++){
 		
 		printf("Enter weight of the this object");
 		scanf("%f",&weight[i]);
 		printf("Enter the price of the object");
 		scanf("%f",&price[i]);
 		ratio[i]=price[i]/weight[i];
	 }
	printf("before\n");
	print(ratio,n);
	
	sort(price,weight,ratio,n);
	printf("after\n");
	print(ratio,n);
	printf("enter the max capacity");
	scanf("%f",&w);
	max=max_profit(price,weight,ratio,n,w);
	printf("max profit collected is:%f",max);
	
	

	 return 0;
	 
 }
 void sort(float price[],float weigh[],float ratio[],int n){
 	
 	int i ,j,t1,t2,t3;
 	for (i=0;i<n;i++){
 		
 		for (j=0;j<n-i-1;j++){
 			
 			if (ratio[j]<ratio[j+1])
				{
					t1=ratio[j];
					ratio[j]=ratio[j+1];
					ratio[j+1]=t1;
					
					t2=weigh[j];
					weigh[j]=weigh[j+1];
					weigh[j+1]=t2;
					
					t3=price[j];
					price[j]=price[j+1];
					price[j+1]=t3;
					
	
		 		}	
		 	 }
	 }
 }
 float max_profit(float price[],float weigh[],float ratio[],int n,float w){
 	
 	int i,j,k;
 	float s=0;
 	for(i=0;i<n;i++){
 		
 		if(weigh[i]<=w){
 			
 			s=s+price[i];
 			w=w-weigh[i];
		 }
		else if (weigh[i]>w){
			
			s=s+ ratio[i]*w;
			w=0;
		}
		if (w<=0){
			break;
		} 
	 }
 	return s;
 }
 
 void print(float arr[],int n){
 	
 	int i,j;
 	
 	for(i=0;i<n;i++){
 		
 		printf("%f,",arr[i]);
	}
		 	 
 }
 
 
 
 
 
 
 
 
