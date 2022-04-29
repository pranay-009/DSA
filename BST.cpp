#include <stdio.h>
#include <stdlib.h>

typedef struct s{
	int data;
	struct s* left;
	struct s* right;
}Node;
Node* create(Node*);
Node* Build(Node*);
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
	Build(curr);
	printf("\nDisplay the tree in inorder:");
	curr=root;
	display(curr);
	return 0;
	
}
// node creation
Node* create(Node* newnode){
	newnode=(Node*)malloc(sizeof(Node));
	printf("Enter data to your node");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
	
}
Node* Build(Node* head){
	Node* l_tree=NULL;
	Node* r_tree=NULL;
	Node* newnode;
	Node* curr;
	curr=head;
	printf("do you want to enter node in this tree?");
	int f=0;
	scanf("%d",&f);
	if(f==1){
	newnode=create(newnode);
	}
	while(f==1){
		//newnode=create(newnode);
		if(newnode->data<=curr->data && curr->left!=NULL){
			curr=curr->left;
			continue;
			
		}
		else if(newnode->data<=curr->data && curr->left==NULL){
			l_tree=newnode;
			curr->left=l_tree;
			Build(head);
			break;
		}
		else if(newnode->data>curr->data && curr->right!=NULL){
			curr=curr->right;
			continue;
			
		}
		else if(newnode->data>curr->data && curr->right==NULL){
			r_tree=newnode;
			curr->right=r_tree;
			Build(head);
			break;
		}
		else{
			break;
		}
	}
		
		
		}

Node* display(Node* curr)
{

		if(curr!=NULL){
			display(curr->left);
			printf("%d,",curr->data);
			display(curr->right);
		}
		
	}
	

