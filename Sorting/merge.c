#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int l,int mid,int h)
{
    int i=l,k=l,j=mid+1;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
    {
        B[k++]=A[i];
    }
    for(;j<=h;i++)
    {
        B[k++]=A[j];
    }
    for(i=l;i<=h;i++)
    {
        A[i]=B[i];
    }
}

void imergesort(int A[],int n)
{
    int i,p,l,h,mid;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
        if(p/2<n-i)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,n-1);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
}

int main()
{
    int A[]={34,2,57,45,33,89,4};
    int n=7;
    imergesort(A,n);

    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}