/*Q1. 
Given the breadth-first traversal, realize a complete binary tree (CBT) with an array. 
Implement the following: (a) Given the index of a node, identify the node’s children and parent, 
(b) Identify and print the available parent-left child-right child node combinations available in the CBT, 
(c) Identify and print the leaf nodes available in the CBT.*/

#include <stdio.h>
#include <stdlib.h>

int size;
struct node{
	int element;
	struct node *r;
	struct node *l;
}*new=NULL,*root=NULL,*ptr=NULL;

void first(int index, int arr[]);
void second(int index, int arr[]);
void third( int arr[]);

int main(){
	int choice,index;
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	int count=size/2;
	int arr[size];
	printf("\nEnter the Breadth First traversal: ");
	for(int i=0;i<size;i++) 
		scanf("%d",&arr[i]);
	printf("\nBreadth first traversal obtained..");
	
	L1:printf("\n1:Get parent and child for any position , 2:get parent and child combo , 3:Get the leaf nodes , Any:Exit");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			P: printf("\nEnter the position to check: ");
			scanf("%d",&index);
			if(index<1||index>size){
				printf("Out of index...\n");
				goto P;
			}
			else{
				first(index-1,arr);
			}
			break;
		case 2:
			printf("\nThis tree has total %d parents.",count);
			for(int i =0;i<count;i++) second(i,arr);
			break;
		case 3:
			third(arr);
			break;
		default:
			printf("Program Closed...\n");
			exit(EXIT_SUCCESS);
	}
	goto L1;
	return 0;
}

void first(int index, int arr[])
{
    int parent, lchild, rchild;
    lchild = (2*index)+1; 
    rchild = (2*index)+2; 
    if(lchild < size)
        printf("\nLeft child of %d: %d.", arr[index], arr[lchild]); 
    else 
        printf("\nLeft child of %d: Not found", arr[index]); 
    if(rchild < size)
        printf("\nRight child of %d: %d.", arr[index], arr[rchild]); 
    else 
        printf("\nRight child of %d: Not found", arr[index]); 
        
    if(index == 0)
    	printf("\nParent doesn't exist, because the node you selected is root of the tree."); 
    else
    {
        parent = (index-1)/2; 
        printf("\nParent of %d: %d", arr[index], arr[parent]); 
    }
}

void second(int index, int arr[])
{
    int lchild, rchild; 
    lchild = (2*index)+1; 
    rchild = (2*index)+2;  
    printf("\nParent: %d", arr[index]) ; 
    if(lchild < size)
        printf("\nLeft child of %d: %d.", arr[index], arr[lchild]); 
    else 
        return; 
    if(rchild < size)
        printf("\nRight child of %d: %d.", arr[index], arr[rchild]); 
    else 
        return;
}

void third(int arr[])
{
    printf("\nLeafs present in the tree is/are: ");  
    for(int i = 0; i < size; i++)
    {
        if(((i*2)+1)  < size)
            continue; 
        else 
            printf("%d ", arr[i]);
    }
 }


/*Q2 Construct a binary search tree (BST) using a linked list and perform Inorder, Preorder, and Postorder Traversal*/

#include <stdio.h>
#include <stdlib.h>
struct tree{
	int element;
	struct tree *rchild;
	struct tree *lchild;
}*ptr=NULL,*root=NULL;

struct tree* create(int x);
struct tree* insert(struct tree *root,int x);
void inorder(struct tree *root);
void preorder(struct tree *root);
void postorder(struct tree *root);

int main(){
	int choice,element;
	L1:printf("1:Insert , 2:Inorder Traversal , 3:Preorder Traversal , 4:Postorder Traversal , Any:Exit\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the element to be inserted: ");
			scanf("%d",&element);
			if(root==NULL) root = create(element);
			else insert(root,element);
			printf("Element Inserted...\n");
			break;
		case 2:
			printf("Inorder traversal of the tree is: ");
			inorder(root);
			break;
		case 3:
			printf("\nPreorder Traversal of the tree is: ");
			if(root==NULL) printf("\nTree is Empty");
			else preorder(root);
			break;
		case 4:
			printf("\nPostorder traversal of the tree is: ");
			if(root==NULL) printf("\nTree is Empty");
			else postorder(root);
		default:
			printf("\nProgram Closed...\n");
			exit(EXIT_SUCCESS);
	}
	goto L1;
	return 0;
}

struct tree *create(int x){
	ptr = malloc(sizeof(struct tree));
	ptr->element = x;
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	
	return ptr;
}

struct tree *insert(struct tree *root, int x){
	if(root==NULL) return create(x);
	else if(x>root->element)
		root->rchild=insert(root->rchild,x);
	else root->lchild = insert(root->lchild,x);
	return root;
}

void inorder(struct tree *root){
	if(root!=NULL){
		inorder(root->lchild);
		printf("|%d| ",root->element);
		inorder(root->rchild);
	}
}

void preorder(struct tree *root){
	if(root!=NULL){
		printf("|%d| ",root->element);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(struct tree *root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("|%d|" ,root->element);
	}
}
