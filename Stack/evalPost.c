#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node * next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node *));
    if(t==NULL)
    {
        printf("Stack is Full\n");
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
        x=top->data;
        top=top->next;
        free(t);
    }
    return x;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='/' || x=='*')
       return 0;
    else   
       return 1;
}

int eval(char *postfix)
{
    int i,r=0,x1,x2;
    int len=strlen(postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop();
            x1=pop();
            switch(postfix[i])
            {
                case '+':
                    r=x1+x2;
                    break;

                case '-':
                    r=x1-x2;
                    break; 

                case '/':
                    r=x1/x2;
                    break; 

                case '*':
                    r=x1*x2;
                    break;             
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix="234*+82/-";
    printf("The Result is :%d",eval(postfix));
    return 0;
}