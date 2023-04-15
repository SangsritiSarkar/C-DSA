#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL;

void create(int A[],int n)
{
    struct Node *t, *last;
    int i;
    t=(struct Node *)malloc(sizeof(struct Node));
    first=(struct Node *)malloc(sizeof(struct Node));
    last=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }


}

int count(struct Node *p) //length of linked list
{
    int l=0;
    while(p!=0)
    {

        l++;
        p=p->next;
    }
    return l;
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>count(p))
    {
        return;
    }

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1 && p;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void Display(struct Node *p)
{
     while(p!=0)
     {
        printf("%d ",p->data);
        p=p->next;
     }
}

int main()
{
    int n,i,pos,a;
    int A[]={3,5,2,7};
    create(A,4);
    Insert(first,4,10);
    Display(first);
    return 0;
}