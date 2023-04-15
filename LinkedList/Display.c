#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;  //NOPINTING ANYWHERE ...therefore NULL PTR

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node ));  //first node created in heap
    first->data=A[0];
    first->next=NULL;   // first node not pointing anywhere yet
    last=first;         // last node =first 
    
    for(i=1;i<n;i++)  //i=1 as 0th element already created
    {
        t=(struct Node *)malloc(sizeof(struct Node ));  //each node created in heap
        t->data=A[i];
        t->next=NULL;  //node not pinting anywhere yet
        last->next=t;  //last next pointing to t
        last=t;        //last node should move on to t
    }
}

void displayLL(struct Node *p)//p not needed to be in heap ..as it first node..already created in heap
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;

    }
}

int main()
{
    int A[]={3,5,7,9,11};
    create(A,5);
    displayLL(first);
    return 0;
}