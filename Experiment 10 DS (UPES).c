/*Q1. Get the number of vertices of a graph and adjacency matrix. 
Check if the graph is a digraph or an undirected graph. [Hint: The matrix for an undirected graph is symmetric.]*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v, temp, count = 0;
    printf("\nEnter the number of vertices in the graph: "); 
    scanf("%d", &v); 
    int adj_mat[v][v];
    for(int i = 0; i < v; ++i)
    {
        for(int j = 0; j < v; ++j)
        {
            L1: 
                printf("\nEnter '1' if the %d is connected to %d, and if are not connected than press '0': ", i+1, j+1); 
                scanf("%d", &temp); 
            if(temp > 1 || temp < 0)
            {
                printf("\nWrong Input...");
                goto L1;     
            }
            else
            {
                adj_mat[i][j] = temp;   
                printf("\nInput recorded…Insert Next Element\n"); 
            }
        }
    }
    for(int i = 0; i < v; ++i)
    {
        for(int j = 0; j < v; ++j)
        {
            if(adj_mat[i][j] != adj_mat[j][i])
            {
                count = 1; 
                break; 
            }
        }
        if(count == 1)
        {
            break; 
        }
    }
    if(count == 1)
        printf("\nThis adjacency matrix is for diagraph.");
    else if(count == 0)
        printf("\nThis adjacency matrix is for the undirected graph.");
    return 0; 
}


/*Q2 Write a menu-driven program to obtain vertex IDs (characters ‘A’, ‘B’, ‘C’, etc.) in a character array and adjacency matrix for a digraph and an undirected graph.
Implement separate functions to display: (a) Degree of all vertices of the undirected graph, 
(b) In-degree and out-degree of all vertices of the digraph, (c) Adjacency matrices.*/

#include<stdio.h>
#include<stdlib.h>

int size; 
 
void arrug(int temp_arr[][size], char vertex[]); 
void arrdg(int temp_arr[][size], char vertex[]);
void getdegreeud(int temp_arr[][size], char vertex[]); 
void getdegreedg(int temp_arr[][size], char vertex[]);
void show(int temp_arr[][size], char vertex[]);
void menu(int choice, int uarr[][size], int darr[][size], char vertex[]);

int main()
{ 
    int command;
    printf("Enter the number of vertex: "); 
    scanf("%d", &size); 
    char vertex[size]; 
    int udg[size][size]; 
    int dg[size][size]; 
    printf("\nEnter the vertex IDs\n");
    for(int i = 0; i < size; ++i)
    {
        scanf(" %c", &vertex[i]); 
    }
    L1:printf("\nGraph type:\n1.Undirected Graph\n2.Directed Graph\nInput: ");
        scanf("%d", &command);
        if(command < 0 || command > 2)
        {
            printf("\nInvalid Input.");
            goto L1; 
        }
        else
        {
            menu(command, udg, dg, vertex); 
        }
    return 0; 
}

void arrug(int temp_arr[][size], char vertex[])
{
    int temp; 
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nIs %c is connected to %c: ", vertex[i], vertex[j]);     
            scanf("%d", &temp);
             if(temp > 1 || temp < 0)
            {
                printf("\nInvalid input.Try again..."); 
                goto menu;     
            }
            else
            {
                temp_arr[i][j] = temp;   
                if(i < size-1 || j < size-1)
                    printf("\nInput recorded..\n"); 
            }
        }
    }
}

void arrdg(int temp_arr[][size], char vertex[])
{
    int temp; 
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nConnectivity Status of %c and %c: ", vertex[i], vertex[j]);     
            scanf("%d", &temp);
             if(temp > 2 || temp < 0)
            {
                printf("\nInvalid input.Try again..."); 
                goto menu;     
            }
            else
            {
                temp_arr[i][j] = temp; 
                if(i < size-1 || j < size-1)  
                    printf("\nInput recorded..\n"); 
            }
        }
    }
}

void getdegreeud(int temp_arr[][size], char vertex[])
{
    for(int i = 0; i < size; ++i)
    {
        int counter = 0;
        for(int j = 0; j < size; ++j)
        {
            if(temp_arr[i][j] == 1)
                counter++;
        }
        printf("\n%c has degree %d.", vertex[i], counter); 
    }
}

void getdegreedg(int temp_arr[][size], char vertex[])
{
    for(int i = 0; i < size; ++i)
    {
        int counter = 0, count = 0;
        for(int j = 0; j < size; ++j)
        {
            if(temp_arr[i][j] == 1)
                counter++; 
            else if(temp_arr[i][j] == 0)
                count++; 
        }
        printf("\n%c has out-degree: %d and in degree: %d.", vertex[i], counter, count); 
    }
}

void show(int temp_arr[][size], char vertex[])
{
    printf("\n   ");
    for(int i = 0; i < size; i++)
        printf("%c ", vertex[i]);
    for(int i = 0; i < size; ++i)
    {
        printf("\n%c  ", vertex[i]); 
        for(int j = 0; j < size; ++j)
            printf("%d ", temp_arr[i][j]);
    }
}

void menu(int choice, int uarr[][size], int darr[][size], char vertex[])
{
     if(choice == 1)
            {
                printf("\nEnter the data for Undirected Graph\n(If mentioned vertex are connected insert 1, if not insert 0.)\n"); 
                arrug(uarr, vertex);
                printf("\nAdjacency Matrix for the Undirected Graph has been obtained.");
            }
            else if(choice == 2)
            {
                printf("\n(If edge is directed from 1st to 2nd insert 1, else insert 0.\nIf vertex are not connected then enter 2.)\n");
                arrdg(darr, vertex); 
                printf("\nAdjacency Matrix for the Directed Graph has been obtained.");
            }
    int command;
    menu:
        printf("\nOperation Available\n1.Degree of vertex(in-degree/out-degree for diagraph OR degree for undirected graph\n2.show Adjacency Matrix\n3.Exit\nChoice: "); 
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            if(choice == 1)
            {
                printf("\nDegrees of all the vertex of the Undirected Graph is: \n"); 
                getdegreeud(uarr, vertex);
            }
            else if(choice == 2)
            {
                printf("\nIn-Degree and Out-Degree of the vertex of the Diagraph: \n"); 
                getdegreedg(darr, vertex); 
            }
            break; 
        case 2:
            if(choice == 1)
            {
                printf("\nAdjacency Matrix for the Undirected Graph is: \n\n"); 
                show(uarr, vertex); 
            }
            else if(choice == 2)
            {
                printf("\nAdjacency Matrix for the Directed Graph is: \n\n"); 
                show(darr, vertex); 
            }
            break;
        case 3:
            exit(0); 
        default:
            printf("\nInvalid Input. Try a valid one.");
            break;
        }
        goto menu;
}
