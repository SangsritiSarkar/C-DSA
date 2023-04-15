#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
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
    } while (p!=Head);
    return l;
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

void Rdisplay(struct Node *p)
{
    static int flag=0;
    if(p!=Head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
    flag=0;
    printf("\n");
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>length(p))
    {
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node *));
    t->data=x;
    if(index==0)
    {
        if(Head==NULL)
        {
            Head->next=t;
            t->next=Head;
        }
        else
        {
            t->next=Head;
            while(p->next!=Head)
            {
                p=p->next;
            }
            p->next=t;
            Head=t; //NOT COMPULSORY
        }
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int main()
{
    int A[]={23,45,1,78,56};
    create(A,5);
    Insert(Head,4,33);
    display(Head);
    Rdisplay(Head);
    return 0;
}