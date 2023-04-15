#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
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

int count(struct Node *p)
{
    int l=0;
    while(p!=NULL)
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
}

int isSort(struct Node *p)
{
    int x=-65536;
    while(p!=0)
    {
        if(p->data < x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

int main()
{
    int A[]={10,20,3,40,50};
    create(A,5);
    if(isSort(first))
    {
        printf("Sorted\n");
    }
    else
    {
        printf("Not Sorted\n");
    }
    return 0;
}