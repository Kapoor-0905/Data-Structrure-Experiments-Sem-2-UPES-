/*Q1
Using array and functions implement Stack and its operations like insert, delete, and display*/

#include<stdio.h>
#include <stdlib.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top=-1;
    printf("Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);

    L1 : printf("\n1:PUSH , 2:POP , 3:DISPLAY , Any:EXIT\n");
    printf("Enter the Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
       	    pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEXIT POINT\n");
            break;
        default:
            printf ("Program closed...\n");
            exit(EXIT_SUCCESS);
    }
	goto L1;    
	return 0;
}
void push()
{
    if(top>=n-1)
        printf("STACK is over flow\n");
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
        printf("Stack is under flow\n");
    else
    {
        printf("The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("The elements in STACK\n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\nPress Next Choice");
    }
    else
        printf("The STACK is empty\n");
}

/*Q2
Reverse a string using a stack implemented with Dynamic 1D Array*/

#include <stdio.h>
#include <string.h>

void swapstr(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void reversestr(char *str, int i, int j){
	if(i<j)
	{
		swapstr(&str[i],&str[j]);
		
		reversestr(str, i+1, j-1);
	}
}

int main(){
	char str[] = "ASHUTOSH";
	reversestr(str,0, strlen(str)-1);
	printf("%s",str);
	return 0;
}
 
/*Q3
Convert infix to postfix expression using stack implemented using Linked List.  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node *next;
}*top=NULL,*pstart=NULL;
void insert(char ch)
{
	struct node *t,*block;
    block=(struct node *)malloc(sizeof(struct node));
    block->next=NULL;
    block->data=ch;
    t=pstart;
    if(pstart==NULL)
    {
    	pstart=block;
    }
    else
    {
	    while(t->next!=NULL)
	    t=t->next;
	    t->next=block;
    }
}
void push (char symbol)
{
	struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=symbol;
    if(top==NULL)
    {
	    top=p;
	    p->next=NULL;
    }
    else
    {
	    p->next=top;
	    top=p;
    }
}

char  pop()
{
	struct node *x,*y;
	char k;
	if(top==NULL)
	{
	    printf("stack underflow\n");
	    return 0;
	}
	else
	{
		x=top;
		top=top->next;
		k=x->data;
		free(x);
		x=NULL;
		return k;
	}
}
void displaypost()
{
	struct node *to;
    if(pstart==NULL)
		printf("Nothing to print!\n");
    else
    {
	    to=pstart;
	    while(to!=NULL)
	    {
	        printf("%c",to->data);
	        to=to->next;
	    }
    }
}

int precedence(char ch)
{
	if(ch=='^')
	return (5);
	else if(ch=='*' || ch== '/')
	return (4);
	else if (ch== '+' || ch== '-')
	return (3);
	else
	return (2);
}
void intopost(char infix[])
{
	int len;
    int index=0;
    char symbol,temp;
    len= strlen(infix);
    while(len>index)
    {
        symbol=infix[index];
        switch(symbol)
        {
        case '(':
	        push(symbol);
	        break;

        case ')':
	        temp=pop();
	        while(temp!='(')
	        {
		        insert(temp);
		        temp=pop();
	        }
	        break; 
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
	        if(top==NULL)
	            push(symbol);
	        else
	        {
		        while(top!=NULL && (precedence(top->data)>=precedence(symbol)))
		        {
		            temp=pop();
		            insert(temp);
			 	}
		        push(symbol);
			 }   
	        break;
	        
        default:
	        insert(symbol);
	
	    }
	        index=index+1;
    }
    while(top!=NULL)
    {
	    temp=pop();
	    insert(temp);
    }
    displaypost();
    return;
}
int main()
{
	char infix[50];
	printf("enter infix expression: ");
	fgets(infix, 50, stdin);
	printf("\nequivalent postfix expression is---> ");
	intopost(infix);
	return 0;
}
