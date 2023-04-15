#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
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

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=(q)?q->next:NULL;
    }while(p && q && p!=q);
    return (p==q)?1:0;
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

int main()
{
    struct Node *t1,*t2;
    int A[]={3,53,24,7,2,67,5};
    create(A,7);
    t1=first->next->next;
    t2=first;
    while(t2->next!=0)
    {
        t2=t2->next;
    }
    t2->next=t1;
    //display(first);
    printf("%d\n ",isLoop(first));
    return 0;
}