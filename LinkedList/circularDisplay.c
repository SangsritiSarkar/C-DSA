#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    int i;
    struct Node *t, *last;
    Head=(struct Node *)malloc(sizeof(struct Node*));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node*));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    } while (h!=Head);
    printf("\n");
}

void Rdisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag ==0)
    {
        flag=1;
        printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag=0;
}

void main()
{
    int A[]={3,6,54,79,56};
    create(A,5);
    display(Head);
    Rdisplay(Head);

}