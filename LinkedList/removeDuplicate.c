#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node*));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node*));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void removeDuplicates(struct Node *p)
{
    struct Node *q;
    q=first->next;
    while(q!=0)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void main()
{
    int A[]={10,10,20,30,40,40,40,50,60,70,70,70};
    create(A,12);
    removeDuplicates(first);
    display(first);
}