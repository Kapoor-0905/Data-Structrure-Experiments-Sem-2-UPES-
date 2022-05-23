/*Q1
Get student SAP-ID and categorize them into their 10 families based on the last three digits. 
[Example-1: Student with SAP-ID 5000423 belongs to family 9, 
Example-2: Student with SAP-ID 5000425 belongs to family 2 based on the last three digits.]*/ 

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct body{
	int data;
	struct body *next;
};
struct body *table[SIZE]={NULL},*ptr;

int getkey(int sap){
	int key=sap%10;
	sap/=10;
	key+=sap%10;
	sap/=10;
	key+=sap%10;
	key= key%10 + key/10;
	return key;
}

void insert(){
	int i,id;
	printf("Enter a SAP ID: ");
	scanf("%d",&id);
	i=getkey(id);
	struct body * newnode=(struct body *)malloc(sizeof(struct body));
	newnode->data=id;
	newnode->next = NULL;
	if(table[i] == NULL)
	table[i] = newnode;
	else{
		ptr=table[i];
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;

	}
printf("Id inserted in the table!!");
}

void display(){
	int i;
	printf("Family SAP ID");
	printf("\n-----------------");
	for(i=0;i<SIZE;i++){
		printf("\n%d: ",i);
		if(table[i] == NULL){
			printf("No ID found in the family!");
		}
		else{
			for(ptr=table[i];ptr!=NULL;ptr=ptr->next)
			if(ptr->next != NULL)
				printf("%d, ",ptr->data);
	else
		printf("%d",ptr->data);
		}
	}
}

int main(){
	int job,id,i = 1;
	while(i = 1){
		printf("Menu\n=================");
		printf("\n1.Insert\n2.Display\n3.Exit\nEnter choice:");
		scanf("%d",&job);
		switch(job){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
			default:
				printf("Enter Valid Choice!");
		}
	}
	return 0;
}

/*Q2
Implement a Hash table using arrays (dynamic array) and Linear probing as a Collision avoidance strategy. 
Perform Insert, Delete and Search operations on the Hash table using the above Hash function.*/

#include <stdio.h>
#include <stdlib.h>

int size,i,ele,choice,index,count=0;

void display(int *array,int size)
{
	if(count==0) printf("Empty hashtable\n");
		else{
		int i;
		printf("value\tkey\n");
		for(i=0;i<size;i++)
		{
			printf("%d\t%d\n",array[i],i);
		}
	}
}

void collision(int *array, int size){
	printf("collision has occured in index %d\n",index);
	for(int i=index,j=size;j>0;j--){
		i = (i+1) % size;
		if(array[i]==-1){
			array[i] = ele;
			break;
		}
	}
}

int main(){
	printf("Enter the size of the hash table: ");
	scanf("%d",&size);
	int hashtable[size];
	for(i=0;i<size;i++)
		hashtable[i] = -1;
		
	while(1){
		printf("1:Continue\t2:Display\t");
		scanf("%d",&choice);
		if(choice ==2)
			break;
		else{
			printf("Enter the Element: ");
			scanf("%d",&ele);
			index=ele%size;
			if(hashtable[index]==-1){
				hashtable[index] = ele;
				count++;
			}
			else{
				collision(hashtable,size);	
			}
		}
	}
	printf("\n");
	display(hashtable,size);
}

/*Q3
Implement a Hash table using an array of Linked Lists with a Separate Chaining Collision avoidance strategy. 
Perform Insert, Delete and Search operations on the hash table using a suitable Hash function*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct body{
	int data;
	struct body *next;
};

struct body *table[SIZE]={NULL},*ptr;
int getkey(int sap){
	int key=sap%10;
	sap/=10;
	key+=sap%10;
	sap/=10;
	key+=sap%10;
	key= key%10 + key/10;
	return key;
}

void insert(){
	int i,id;
	printf("Enter a SAP ID: ");
	scanf("%d",&id);
	i=getkey(id);
	struct body * newnode=(struct body *)malloc(sizeof(struct body));
	newnode->data=id;
	newnode->next = NULL;
	if(table[i] == NULL)
		table[i] = newnode;
	else{
		ptr=table[i];
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
	printf("Id inserted in the table!!");
}

void display(){
	int i;
	printf("Family SAP ID");
	printf("\n-----------------");
	for(i=0;i<SIZE;i++){
		printf("\n%d: ",i);
		if(table[i] == NULL){
			printf("No ID found in the family!");
		}
		else{
			for(ptr=table[i];ptr!=NULL;ptr=ptr->next)
			if(ptr->next != NULL)
			printf("%d, ",ptr->data);
	else
		printf("%d",ptr->data);
		}
	}
}

void delete(){
	int i, id;
	printf("\nEnter the SAP ID to delete: ");
	scanf("%d", &id);
	i = getkey(id);
	struct body *temp = table[i], *dealloc;
	if(temp != NULL){
		if(temp->data == id){
			dealloc = temp;
			temp = temp->next;
			free(dealloc);
		}
	}
	else{
		while(temp->next){
			if(temp->next->data == id){
				dealloc = temp->next;
				temp->next = temp->next->next;
				free(dealloc);
			}
			temp = temp->next;
		}
	}
printf("\nElement deleted!");
free(temp);
}

int search(){
	int i, id, c;
	printf("\nEnter the SAP ID to search: ");
	scanf("%d", &id);
	i = getkey(id);
	struct body *temp = table[i];
	while(temp != NULL){
		if(temp->data == id)
			c = 1;
		else
			c = 0;
	temp = temp->next;
	}
	if(c == 1)
		printf("\nElement found at family: %d", i);
	else if(c == 0)
		printf("\nElement not found");
	return 0;
}

int main(){
	int job,id,i = 1;
	while(i = 1){
		printf("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\nEnter choice:");
		scanf("%d",&job);
		switch(job){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				delete();
				break;
			case 4:
				search();
				break;
			case 5:
				exit(0);
			default:
				printf("Enter Valid Choice!");
		}
	}
	return 0;
}
