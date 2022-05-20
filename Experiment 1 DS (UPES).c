/*Q1 
Find the sum of all array elements using recursion*/

#include <stdio.h> 
#include <stdlib.h>

int sum(int a[] , int index , int length){
    if (index>=length)
        return 0;
    return (a[index] + sum(a,index+1,length));
}

int main(){
    int i,sum_array,n;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    if (n<=0){
        printf("Invalid length..\n");
        return 0;
    }
    int a[n];
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum_array= sum(a,0,n);
    printf("Sum of the elements of the array is %d",sum_array);
    return 0;
}

/*Q2
Convert uppercase string to lowercase using for loop (do not use built-in functions).*/

#include <stdio.h>
int main(){
    int i,size;
    printf("Enter the length of the string: ");
    scanf("%d",&size);
    char string[size];
    printf("Enter a upper case string\n");
    scanf("%s",&string);
    printf("The entered uppercase string is : %s\n",string);
    for(i=0;i<size;i++){
        if (string[i]>='A' || string[i]<='Z'){
            string[i]+=32;
        }
    }
    printf("The lowercase string is: %d",string);
    return 0;
}

/*Q3
Find the product of two matrices*/

#include <stdio.h>
int main(){
    int r1,c1,r2,c2,c,d,k,sum=0;
    int first[10][10], second[10][10],multiply[10][10];
    printf("Enter the number of rows and columns of the first matrix: \n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the elements of the first matrix: \n");
    for(c=0;c<r1;c++){
        for (d=0;d<c1;d++){
            scanf("%d", &first[c][d]);
        }
    }
        
    printf("Enter the rows and columns of the second matrix: \n");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2)
        printf("The multiplication of the matrices is not possible \n");
    else{
        printf("Enter the elements of the second matrix: \n");
        for(c=0;c<r2;c++){
            for(d=0;d<c2;d++){
                scanf("%d", &second[c][d]);
            }
        }
        for(c=0;c<r1;c++){
            for(d=0;d<c2;d++){
                for(k=0;k<r2;k++){
                    sum+=first[c][k]*second[k][d];
                }
                multiply[c][d] =  sum;
                sum=0;
            }
         }     
        printf("Product of the matrices: \n");
        for(c=0;c<r2;c++){
            for(d=0;d<c2;d++){
                printf("%d\t",multiply[c][d]);
            }
            printf("\n");
        }
    }
    return 0;
}
