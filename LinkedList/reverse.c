#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node*));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node*));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int count(struct Node*p)
{
    int l=0;
    while(p!=0)
    {
        l++;
        p=p->next;
    }
    return l;
}

void reverse1(struct Node *p)  //REVERSING ELEMENTS
{
    int *A,i=0;
    struct Node *q=p; //another ptr q is taken for traversing as p is pting at first
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void reverse2(struct Node *p)   // REVERSING LINKS USING SLIDING POINTERS
{
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverse3(struct Node *q, struct Node *p)   //RECURSIVE REVERSE FOR L.L.
{
    if(p!=NULL)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

void display(struct Node*p)
{
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void main()
{
    int A[]={20,10,34,57,40};
    create(A,5);
    //reverse1(first);    
    //reverse2(first);
    reverse3(NULL,first);
    display(first);
}