#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop()
{
    struct Node *t;
    char x=-1;
    if(top==NULL)
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

int pre(char x)
{
    if(x=='+' || x=='-')
      return 1;
    else if(x=='*' || x=='/') 
      return 2;
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
       return 0;
    else
       return 1;   
}

char *InToPost(char *infix)
{
    int i=0,j=0;
    int len=strlen(infix);
    char *postfix;
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b*c";
    push('#');
    char *postfix = InToPost(infix);
    printf("%s", postfix);
}