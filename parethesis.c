#include <stdio.h>
char push(char[],int,int,char );
char pop(char[],int);
int check(char,char);
int main(){
	char arr[100]={"[[[[[[{()}]]]]]]"};
	char stack[100];
	int max=0;
	int i,k=0;
	while(true){
		if(arr[k]== NULL){
			break;
		}
		max=max+1;
		k=k+1;
		
	}
	printf("Expression:%s\n",arr);
	printf("length of expression:%d\n",k);
//	printf("%d",max);
	int top=0;
	int max2=k;
	char item;
	int n=max;
	int flag=1;
	
	
	for(i=0;i<n;i++){
		if(arr[i]=='{'||arr[i]=='['||arr[i]=='('){
			push(stack,top,max2,arr[i]);
			//printf("top:%d",top);
			top=top+1;
			//printf("stack top:%c\n",stack[top]);

			item =pop(arr,max-1);
			max=max-1;
		//	printf("popped item:%c\n",item);
			
			
			flag=check(arr[i],item);
			
			if(flag==0){
				printf("not balanced");
				break;
			}
		}
		if(arr[i]==']'||arr[i]=='}'||arr[i]==')'){
			break;
		}
	}
			
	if(flag==1){
		printf("balanced");
		
	}
}
			
			

char push(char arr[],int top,int max,char x){
	int i,j;
	if(top==-1){
		printf("stack is empty!\n");
		arr[top]=x;
		top=top+1;
	}
	else if(top==max){
		printf("overflow!\n");
	}
	else{
		arr[top]=x;
		//printf("x=%cn",x);
		top=top+1;
		
	}
	
}
char pop(char arr[],int top){
	char x;
	int i;
	if(top==-1){
		printf("stack is underflow\n");
	}
	else{
		x=arr[top];
		//printf("%s",x);
		top=top-1;
		return x;
	}
	
	
}

int check(char c1,char c2){
	if(c1=='{' && c2=='}'){
		return 1;
	}
	else if(c1=='['&& c2==']'){
		return 1;
	}
	else if(c1=='('&&c2==')'){
		return 1;
}
	else{
		return 0;
	}	
	
}
