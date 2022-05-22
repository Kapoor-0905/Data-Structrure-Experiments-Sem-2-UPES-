/*Q1
Using array and functions implement Circular Queue data structure and its operations like insert, delete, and display..*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in = 0, out = 0;
int count = 0;
int size;

void enqueue(int *queue, int size );
void dequeue(int *queue);
void display(int *queue);

int main(){
	printf(“Enter the size of the queue: “);
	scanf(“%d”,&size);
	int queue[size];
	
	L1 : printf(“1:Insert , 2:Delete , 3:display , Any:Exit\n”);
	int choice;
	printf(“Enter your choice: “);
	scanf(“%d”,&choice);
	switch (choice){
case 1:
			enqueue(queue, size);
			break;
		case 2:
			dequeue(queue);
			break;
		case 3:
			display(queue);
			break;
		default:
			printf(“Program closed..”);
			exit(EXIT_SUCCESS);
	}
	goto L1;
	return 0;
}
void enqueue(int *queue, int size){	
if(count == size) printf(“full\n”);
	else{
		printf(“Enter the element: “);
		scanf(“%d”,&queue[in]);
		in = (in + 1)%size;
		count+=1;
	}
}

void dequeue(int *queue){
	if(count==0) printf(“The queue is empty..\n”);
	else{
		printf(“deleted element is: %d\n”,queue[in]);
		in = (in+1)%size;
		count -= 1;
	}
}

void display(int *queue){
	if(count == 0)
		printf(“The Queue is empty..\n”);
	else if(out>in){
		printf(“The elements are: \n”);
		for(int i=in;i<=out;i++)
			printf(“%d”,queue[i]);
	}
	else{
		printf(“The Elements are: \n”);
		for(int i=in;i<size;i++)
			printf(“%d\n”,queue[i]);
	}
}


/*Q2
Using array and functions implement Priority Queue and its operations (insert, delete, display)*/

#include <stdio.h>
#include <stdlib.h> 
#define MAX 10

void create_queue(); 
void insert_element(int); 
void delete_element(int); 
void check_priority(int); 
void display_priorityqueue(); 

int pqueue[MAX]; 
int front, rear; 

void main() 
{ 
    int n, choice;  
    printf("\nEnter 1 to insert element by priority "); 
    printf("\nEnter 2 to delete element by priority "); 
    printf("\nEnter 3 to display priority queue "); 
    printf("\nEnter 4 to exit");  
    create_queue();  
    while (1) { 
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);   
        switch(choice) { 
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            insert_element(n); 
            break; 
        case 2: 
            printf("\nEnter element to delete : "); 
            scanf("%d",&n); 
            delete_element(n); 
            break; 
        case 3: 
            display_priorityqueue(); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("\n Please enter valid choice"); 
        } 
    } 
}  
void create_queue() {
    front = rear = -1; 
}  
void insert_element(int data) 
{ 
    if (rear >= MAX - 1) { 
        printf("\nQUEUE OVERFLOW"); 
        return; 
    } 
    if ((front == -1) && (rear == -1)) { 
        front++; 
        rear++; 
        pqueue[rear] = data; 
        return; 
    }    
    else 
        check_priority(data); 
    rear++; 
}  
void check_priority(int data) 
{ 
    int i,j;  
    for (i = 0; i <= rear; i++) { 
        if (data >= pqueue[i]){ 
            for (j = rear + 1; j > i; j--) 
                pqueue[j] = pqueue[j - 1]; 
            pqueue[i] = data; 
            return; 
        } 
    } 
    pqueue[i] = data; 
}  
void delete_element(int data)  
{ 
    int i;  
    if ((front==-1) && (rear==-1)) { 
        printf("\nEmpty Queue"); 
        return; 
    }  
    for (i = 0; i <= rear; i++) { 
        if (data == pqueue[i]){ 
            for (; i < rear; i++) 
            	pqueue[i] = pqueue[i + 1]; 
            pqueue[i] = -99; 
            rear--; 
            if (rear == -1) 
               front = -1; 
            return; 
        } 
    } 
    printf("\n%d element not found in queue", data); 
} 
void display_priorityqueue() 
{ 
    if ((front == -1) && (rear == -1)){ 
        printf("\nEmpty Queue "); 
        return; 
	}  
    for (; front <= rear; front++) 
    	printf(" %d ", pqueue[front]); 
    front = 0; 
}


/*Q3
Using linked list implement Double Ended Queue (Input Restricted Deque and Output Restricted Deque) 
and its operations (insert, delete, display)*/

#include <stdio.h>
#include <stdlib.h>

struct queue{
	int no;
	struct queue *next;
}*new,*first=0,*ptr,*temp;

int count =0;
void enq_begin();
void enq_end();
void deq_begin();
void deq_end();
void display();

void createblock(){
	new = (struct queue *)malloc(sizeof(struct queue));
	printf("Enter the data: ");
	scanf("%d",&new->no);
	new->next=0;
	count++;
}

int main(){
	int choice = 0; 
	while(1){
		printf("1:Insert In Beginning of Queue\n2:Insert In the end of Queue\n3:Delete from the Beginning of Queue\n4:Delete from the End of Queue\n5:Display\nAny:Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enq_begin();
				break;
			case 2:
				enq_end();
				break;
			case 3:
				deq_begin();
				break;
			case 4:
				deq_end();
				break;
			case 5:
				display();
				break;
			default:
				printf("Program Closed...\n");
				exit(EXIT_SUCCESS);
		}
	}
}

void enq_begin(){
	createblock();
	
	if (first==0) first=new;
	else{
		new->next = first;
		first = new;
	}
}

void enq_end(){
	createblock();
	
	if(first==0) first=new;
	else{
		for(ptr=first;ptr->next!=0;ptr=ptr->next);
		ptr->next=new;
	}
}

void deq_begin(){
	if(first==0) printf("The Queue is Empty...\n");
	else if(first->next==0){
		printf("Deleted Element is: %d\n",first->no);
		free(first);
		first=0;
		count=0;
	}
	else{
		printf("Deleted Element is: %d\n",first->no);
		temp = first->next;
		free(first);
		first = temp;
		count -= 1;
	}
}

void deq_end(){
	if(first==0) printf("The Queue is Empty...\n");
	else if(first->next==0){
		printf("Deleted Element is: %d\n",first->no);
		free(first);
		first=0;
		count=0;
	}
	else{
		for (ptr=first; ptr->next->next !=0; ptr=ptr->next);
		printf("Deleted Element is: %d\n",ptr->next->no);
		free(ptr->next);
		ptr->next=0;
		count = count-1;
	}
}

void display()
{
	if(first==0) printf("The Queue is empty...\n");
	else{
		printf("The Elements are: ");
		for(ptr=first;ptr!=0;ptr=ptr->next)
			printf("%d ",ptr->no);
		printf("\n");
	}
}

