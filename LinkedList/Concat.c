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

void Concat(struct Node *p, struct Node *q)
{
    third=p;
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=q;
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
    int A[]={10,3,4,20,9};
    int B[]={200,45,100,67,80};
    printf("First:\n");
    create1(A,5);
    display(first);
    printf("Second:\n");
    create2(B,5);
    display(second);
    printf("Concatenated List: \n");
    Concat(first,second);
    display(third);

}