/*Q!
Design a structure to represent a complex number. 
Get two complex numbers and find the sum of them using a function to which structure is passed as argument*/

#include <stdio.h>
struct complex{
    float r, img;
}complx;

complex add_complx (complex cmplx1,complex cmplx2){
    complex final; 
    final.r = cmplx1.r + cmplx2.r;  
    final.img = cmplx1.img + cmplx2.img; 
    return final; 
}
int main(){
    complex cmplx1, cmplx2,cmplx_final;
    printf("Enter the first complex number: \n");
    printf("Enter the real part:  ");
    scanf("%f",&cmplx1.r);
    printf("\nEnter the imaginary part: ");
    scanf("%f",&cmplx1.img);
    printf("\nComplex number 1 = %.2f + (%.2f)i",cmplx1.r , cmplx1.img);

    printf("\nEnter the second complex number: \n");
    printf("Enter the real part:  ");
    scanf("%f",&cmplx2.r);
    printf("\nEnter the imaginary part: ");
    scanf("%f",&cmplx2.img);
    printf("\nComplex number 1 = %.2f + (%.2f)i",cmplx2.r , cmplx2.img);
        
    cmplx_final = add_complx(cmplx1,cmplx2);
    printf("\nSUM of both complex numbers = %0.2f + %0.2f i", cmplx_final.r, cmplx_final.img);
    return 0;
}


/*Q2
Design a structure named ‘student_record’ to store student details like name, sap- id, enrollment-number, birth-date, registration-date, and marks of five subjects. 
The members, birth date, and registration date are defined using another structure named ‘date’ to store date details like day, month, and year. Get data of ‘n’ students, 
compute the average marks obtained by each of them and print their grade sheets. 
Note: Use Nested Structures, each student record is dynamically allocated*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct registeration{
	int date, year;
	char month[20];
}reg;

struct marks{
	int maths,physics,chemistry,computer,biology;
}mark;

struct date_of_birth{
	int date, year;
	char month[10];
}dob;

struct student_record{
	char name[30];
	int sapid, enroll_no;
	struct registeration reg;
	struct date_of_birth dob;
	struct marks mark;
}stu_rec;

int main(){
	int i,n;
	struct student_record stu_rec; 
	printf ("Enter the number of records to be stored: ");
	scanf("%d",&n);
	
	struct student_record *stu;
	stu = (struct student_record *) malloc(n * sizeof(struct student_record)); 
	
	for(i=0;i<n;i++){
		printf("\nEnter the name of student: ");
		scanf("%s",stu[i].name);
			
		printf("Enter the sapid of the student: ");
		scanf("%d",&stu->sapid);
		
		printf("Enter the enrollment number: ");
		scanf("%d",&stu->enroll_no);
		
		printf("Enter the registeration month: ");
		scanf("%s",&stu->reg.month);
		
		printf("Enter the registeration date and year resp.: ");
		scanf("%d %d",&stu->reg.date,&stu->reg.year);
		
		printf("Enter month of birth: ");
		scanf("%s",&stu->dob.month);
		
		printf("Enter the date and year of birth resp.: ");
		scanf("%d %d",&stu->dob.date,&stu->dob.year);
		
		printf("\nEnter the marks as following(maths,physics,chemistry,computer,biology): ");
		scanf("%d %d %d %d %d",&stu->mark.maths,&stu->mark.physics,&stu->mark.chemistry,&stu->mark.computer,&stu->mark.biology);
		
		int total = stu->mark.maths + stu->mark.physics + stu->mark.chemistry + stu->mark.computer + stu->mark.biology;
		float avg = total/5;
		printf("\nName: %s",stu[i].name);
		printf("\nSAPID: %d",stu->sapid);
		printf("\nEnrollment number: %d",stu->enroll_no);
		printf("\nRegisteration Date: %s %d %d",stu->reg.month,stu->reg.date,stu->reg.year);
		printf("\nDate of Birth: %s %d %d",stu->dob.month,stu->dob.date,stu->dob.year);
		printf("\nAverage marks: %f\n",avg);
	}
	return 0;
}


/*Q3
Design a union ‘product’ to store the details of the product purchased like product name, price per unit, the number of quantities purchased, 
and amount spent. Get the name, price per unit, and the number of quantities of the product purchased. 
Calculate the amount spent on the product and then display all the details of the procured product*/

#include <stdio.h>

int main(){
	union product{
		char prdct_name[25];
		int quantity;
		float price,amount;
	};
	
	union product *t , p;
	int x,y;
	t = &p;
	
	printf("Enter the product name: ");
	scanf("%[^\n]s", p.prdct_name);
	printf("Product name: %s\n",t->prdct_name);

	printf("\nEnter the quantity: ");
	scanf("%d",&p.quantity);
	y = t->quantity;
	printf("Quantity: %d\n",t->quantity);
	
	printf("\nEnter the price: ");
	scanf("%f",&p.price);
	x = t->price;
	printf("price: %f\n",t->price);
	
	p.amount = x*y;
	printf("\nAmount: %f",t->amount);
	return 0;
}

/*Q4
. Consider two quadratic equations (Eq1, Eq2) with two positive roots each. Their roots are related as given below: 
a)	One root is common for both equations (choose the biggest positive root during derivation), 
    (ii) The uncommon positive root of Eq1 and Eq2 is the same as the two different positive roots of a third given Quadratic Equation (say x2−15x+56=0).
b)	Sum of the product (SOP) of all four roots taken two at a time is given.
c)	 Find the sum of all the four roots and the quadratic equations Eq1 and Eq2*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int check=0;

struct equation{
	int a,b,c,root1,root2;
	struct equation* next;
};

int display(struct equation* en){
	printf("The quadratic equation is: %dx^2 + %dx + %d",en->a,en->b,en->c);
	return 0;
}

int calc_eqn(struct equation* en){
	en->a = 1;
	en->b = -(en->root1 + en->root2);
	en->c = (en->root1*en->root2);
	return 0;
}

int calc_root(struct equation* en1, struct equation* en2, struct equation* sop,int sum){
	float d;
	d= ((en1->root2 + en2->root2)*(en1->root2 + en2->root2)) - (4*(en1->root2*en2->root2));
	if(d>=0){
		sop->root1 = -((en1->root2 + en2->root2) + sqrt(d))/2;
		sop->root2 = -((en1->root2 + en2->root2) - sqrt(d))/2;
	}
	else
		check=1;
	return 0;
}

int main(){
	struct equation equn1, equn2, equn3, sop;
	float sum, d;
	
	printf("Enter the coffecient of x^2: ");
	scanf("%d",&equn3.a);
	
	printf("Enter the coffecient of x: ");
	scanf("%d",&equn3.b);
	
	printf("Enter the constant term: ");
	scanf("%d",equn3.c);
	
	d = ((equn3.b*equn3.b) - (4*equn3.a*equn3.c-sum));
	
	if(d<0){
		printf("The roots are complex!! Can't proceed.");
		exit(0);
	}
	if(d==0){
		equn3.root1 = -(equn3.b)/2*equn3.a;
		equn3.root2 = -(equn3.b)/2*equn3.a;
		if(equn3.root1<0 ||equn3.root2<0){
			printf("Roots are negaive! ");
			exit(0);
		}
	}
	if(d>0){
		equn3.root1 = (-(equn3.b) - sqrt(d))/(2*equn3.a);
		equn3.root1 = (-(equn3.b) + sqrt(d))/(2*equn3.a);
		if(equn3.root1<0 ||equn3.root2<0){
			printf("Roots are negaive! ");
			exit(0);
		}
	}
	printf("\nEnter sum of products: ");
    scanf("%f", &sum); 
	equn1.root2=equn3.root1;
	equn2.root2=equn3.root2; 
	calc_root(&equn1, &equn2, &sop, sum);
	if(check==1){
		printf("Solution doesn't exists!");
		exit(0);
	}
	if(sop.root1>0) {
		printf("\nWhen common root is: %f", sop.root1);
		equn1.root1=equn2.root1=sop.root1;
		calc_eqn(&equn1);
		calc_eqn(&equn2); 
		display(&equn1);
		display(&equn2);
	}
	if(sop.root2>0) {
		printf("\nWhen common root is: %f", sop.root2);
		equn1.root1=equn2.root1=sop.root2;
		calc_eqn(&equn1);
		calc_eqn(&equn2); 
		display(&equn1);
		display(&equn2);
	}
	return 0;
}


