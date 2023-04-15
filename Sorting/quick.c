#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[], int l, int h)
{
    int i,j;
    int pivot=A[l];
    i=l;
    j=h;
    do
    {
        /* code */
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)swap(&A[i],&A[j]);
    } while (i<j);

    swap(&A[l],&A[j]);
    return j;
}

void quicksort(int A[], int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        quicksort(A,l,j);
        quicksort(A,j+1,h);
    }
}

int main()
{
    int A[]={34,2,57,45,33,89,4};
    int n=7;
    quicksort(A,0,n-1);

    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}