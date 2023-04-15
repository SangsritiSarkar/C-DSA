#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *last, *t;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        
        t=(struct Node*)malloc(sizeof(struct Node));
        t->prev=last;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

int length(struct Node *p)
{
    int l=0;
    while(p!=0)
    {
        l++;
        p=p->next;
    }
    return l;
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
    int a[]= {8,4,6,7,2};
    create(a,5);
    printf("Length is %d: \n",length(first));
    display(first);
    return 0;
}