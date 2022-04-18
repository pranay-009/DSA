#include <stdio.h>
#include <stdlib.h>
typedef struct s{
	int data;
	struct s* left;
	struct s* right;
}Node;
Node* create(Node*);
Node* Build(Node*,Node*);
Node* display(Node*);

int main(){
	Node* root,*curr,*rtree,*ltree,*newnode;
	root=(Node*)malloc(sizeof(Node*));
	printf("enter root data:");
	scanf("%d",&root->data);
	root->left=NULL;
	root->right=NULL;
	curr=root;
	printf("\nlets build a binary tree\n");
	Build(curr,newnode);
	printf("\nDisplay the tree in prefix:");
	curr=root;
	display(curr);
	return 0;
	
}
Node* create(Node* newnode){
	newnode=(Node*)malloc(sizeof(Node));
	printf("Enter data to your node");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
	
}
Node* Build(Node* curr,Node* newnode){
	int f=0;
	Node* ltree=curr->left;
	Node* rtree=curr->right;
	if(curr!=NULL){
		printf("curr has left sub tree 1 if yes 0 if no:");
		scanf("%d",&f);
		if(f==1){
			ltree=create(newnode);
			curr->left=ltree;
			Build(ltree,newnode);
		}
		else{
			ltree=NULL;
			curr->left=NULL;
			
		}	
		printf("curr has right sub tree 1 if yes 0 if no:");
		scanf("%d",&f);

		if(f==1){
			rtree=create(newnode);
			curr->right=ltree;
			Build(rtree,newnode);
		}
		else{
			rtree=NULL;
			curr->right=NULL;
		}
		
		
		}
}
Node* display(Node* curr)
{

		if(curr!=NULL){
			printf("%d,",curr->data);
			display(curr->left);
			display(curr->right);
		}
		
	}
	

