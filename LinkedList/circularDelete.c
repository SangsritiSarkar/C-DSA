#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    Head=(struct Node *)malloc(sizeof(struct Node *));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

int length(struct Node *p)
{
    int l=0;
    do
    {
       l++;
       p=p->next;
    }while(p!=Head);
    return l;
}

void display(struct Node *p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=Head);
    printf("\n");
}

void Rdisplay(struct Node *p)
{
    static int flag=0;
    if(flag==0 || p!=Head)
    {
        flag=1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
    flag=0;
    printf("\n");
}

void delete(struct Node *p, int pos)
{
    int x,i;
    struct Node*q;
    if(pos<0 || pos>length(p))
    {
        return;
    }
    if(pos==1)
    {
        while(p->next!=Head)
        {
            p=p->next;
        }
        x=Head->data;
        if(Head==p)  //WHEN HEAD IS THE ONLY NODE
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(i=0;i<pos-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
}

void main()
{
    int A[]={35,4,67,55,23};
    create(A,5);
    delete(Head,6);
    display(Head);
    Rdisplay(Head);
}