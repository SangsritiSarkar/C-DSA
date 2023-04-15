#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(int A[], int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node *));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n)
{
    struct Node *t,*last;
    int i;
    second=(struct Node *)malloc(sizeof(struct Node *));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *t, *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
           last->next=p;
           last=p;
           p=p->next;
           last->next=NULL;
        }
        else
        {
           last->next=q;
           last=q;
           q=q->next;
           last->next=NULL;
        }
        if(p)last->next=p;
        if(q)last->next=q;
    }
}

void display(struct Node *p)
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
    int A[]={23,46,76,98,100};
    int B[]={2,89,100,117,200};
    printf("First:\n");
    create1(A,5);
    display(first);
    printf("Second:\n");
    create2(B,5);
    display(second);
    printf("Merged List: \n");
    merge(first,second);
    display(third);

}