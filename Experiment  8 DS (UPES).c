/*Q1.
 Store ‘n’ numbers in an array in an unsorted order. Using menu-driven logic perform a search (Linear and Binary Search algorithms) 
 for a given number and report success or failure in the form of a suitable message.
 (Hint: Before performing a Binary search the array should be sorted using the Bubble sort algorithm.)*/

 #include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n);
void display(int arr[],int n);
void bubble_sort(int arr[], int n);
void binary_search(int arr[], int n);

int main(){
	int n, i=0, choice;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of array: ");
	while(i<n){
		scanf("%d",&arr[i]);
		i++;
	}
	L1 : printf("1:Display , 2:Linear Search , 3:Binary Search , Any:Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			display(arr,n);
			break;
		case 2:
			linear_search(arr,n);
			break;
		case 3:
			bubble_sort(arr,n);
			binary_search(arr,n);
			break;
		default:
			printf("Program Closed...\n");
			exit(EXIT_SUCCESS);	
	}
	goto L1;
	return 0;
}

void display(int arr[],int n){
	printf("The array is: ");
	for(int i=0;i<n;i++)
		printf("|%d| ",arr[i]);
}

int linear_search(int arr[],int n){
	int count=0,ele;
	printf("Enter the element to search: ");
	scanf("%d",&ele);
	for(int i=0;i<n;i++){
		if(arr[i] == ele){
			printf("%d found at position %d\n",ele,i+1);
			count++;
		}
	}
	if(count==0) printf("\nElement not found...");
	else	printf("%d ocured %d times in the array",ele,count);
	return 0;
}

void bubble_sort(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void binary_search(int arr[],int n){
	int ele, left=0,right=n-1;
	int mid = (left+right)/2;
	printf("Enter the element to search: ");
	scanf("%d",&ele);
	while(left<=right){
		if(arr[mid]<ele){
			left = mid +1;
			mid = (left+right)/2;
		}
		else if(arr[mid]==ele){
			printf("Element found at position : %d\n",mid+1);
			break;
		}
		else{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	if(left>right) printf("Element not found...\n");
}


/*Q2 
Store ‘n’ numbers in a Linked list. Perform a Linear search for a given number 
and report success or failure in the form of a suitable message*/


#include <stdio.h>
#include <stdlib.h>

struct search{
	int data;
	struct search *next;
}*new,*head;

void createblock(int element);
void searching();

int main(){
	int choice,element;
	while(1){
		printf("\n1:Create , 2:Search , Any:Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the element: ");
				scanf("%d",&element);
				createblock(element);
				break;
			case 2:
				searching();
				break;
			default:
				printf("Program Closed...\n");
				exit(EXIT_SUCCESS);
		}
	}
}

void createblock(int element){
	struct search *ptr = (struct search*)malloc(sizeof(struct search*));
	if(ptr==NULL) printf("The list is full\n");
	else{
		ptr->data=element;
		ptr->next=head;
		head=ptr;
		printf("Element Inserted Successfully...\n");
	}
}

void searching(){
	struct search *ptr;
	int element,i=0,point;
	ptr = head;
	if(ptr==NULL) printf("The list is empty\n");
	else{
		printf("Enter the element to search: ");
		scanf("%d",&element);
		while(ptr!=NULL){
			if(ptr->data==element){
				printf("Element found at %d\n",i+1);
				point = 0;
			}
			else{
				point=1;
				printf("Element not found...\n");
			}
			i++;
			ptr=ptr->next;		
		}
		//if(point==1) 
	}
}


/*Q3
Store ‘n’ numbers in a Hash Table implemented with an Array of Linked Lists. 
Perform a search for a given number and report success or failure in the form of a suitable message*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 10

int getkey(float data);
void createnode(float temp);
void display();
void insert(float data,int key);
void search(float data,int key);

struct hash{
	float data;
	struct hash *next;
}*new=NULL,*ptr=NULL;

struct hash *htable[size] = {NULL};

int main(){
	float data,esearch;
	int choice,key;
	L1:printf("1:Insert , 2:Search , 3:Display , Any:Exit\nEnter your Choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter the element: ");
			scanf("%f",&data);
			key = getkey(data);			
			insert(data,key);
			break;
		case 2:
			printf("Enter the element to search" );
			scanf("%f",&esearch);
			key = getkey(esearch);
			search(esearch,key);
			break;
		case 3:
			display();
			break;
		default:
			printf("Program Closed...\n");
			exit(EXIT_SUCCESS);
	}
	goto L1;
	return 0;
}

int key(float data){
	float temp=data/10.0;
	temp=ceil(temp);
	int key=temp;
	if(key==0) return 0;
	else return (key-1);
}

void createnode(float temp){
	new = malloc(sizeof(struct hash));
	if(new==NULL) printf("MA Failed...\n");
	else{
		new->data = temp;
		new->next = NULL;
	}
}

void insert(float data,int key){
	float temp = data;
	createnode(temp);
	if(htable[key]==NULL) htable[key]= new;
	else{
		ptr = htable[key];
		new->next = ptr;
		htable[key] = new;
	}
	printf("Insertion Done...\n");
}

void display(){
	printf("\nPosition\tData");
	for(int i=0;i<size;i++){
		if(htable[i]==NULL) printf("%d\tIndex Empty",i+1);
		else{
			printf("\n%d\t",i+1);
			for(ptr = htable[i];ptr!=NULL;ptr = ptr->next){
				printf("%.1f",ptr->data);
				if(ptr->next !=NULL) printf(", ");
			}
		}
	}
}

void search(float data, int key){
    int count = 0; 
    for(ptr = htable[key]; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->data == data) count++; 
    }
    if(count == 0) printf("\nElement not found in the hash table.");
    else printf("\nElement found!!\nIndex: %d\nFrequency: %d", key, count);
}

