#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node *));
    if(t==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(t==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p=top;
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(22);
    push(5);
    push(45);

    display();
    printf("%d ",pop());
    //display();
    return 0;
}