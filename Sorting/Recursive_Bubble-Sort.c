#include<stdio.h>
#include<conio.h>
int Bubble_Sort(int array[],int n);
int main()
{
    int array[100],n;
    printf("\tBubble Sort using Recursion--\n\t (Sort in Assending Order)\n\n");
    printf("Enter the length of the Array: ");
    scanf("%d",&n);
    printf("Enter %d number:- ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    Bubble_Sort(array,n);
    printf("\n The Sorted Array:-");
    for(int i=0;i<n;i++)
    printf(" %d ",array[i]);
    getch();
}
/*Function for Performing Bubble Sort using Recursion.*/
int Bubble_Sort(int array[],int n)
{
    int temp;
    // Base case
    if(n==1)
    return;
    /* One pass of bubble sort. After this pass,
    the largest element is bubbled (or moved) to end.*/
    for(int i=0;i<n-1;i++)
    {
        if(array[i]>array[i+1])
        {
        temp=array[i];
        array[i]=array[i+1];
        array[i+1]=temp;
        //for swapping.
        }
    }
    //Largest element is fixed.
    //Recur for remaining array.
       Bubble_Sort(array,n-1);
}