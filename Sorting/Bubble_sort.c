#include<stdio.h>
#include<conio.h>
void Bubble_sort(int array[],int n);
int main(void)
{
    printf("\n Program for Bubble Sort.--");
    int array[100],i,n;
    printf("\n Enter no. of the Element: ");
    scanf("%d",&n);
    printf("\n Enter %d Element: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    Bubble_sort(array,n);
    getch();
}
void Bubble_sort(int array[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("\n Sorted list are:--\n");
    for(i=0;i<n;i++)
        printf("%d ",array[i]);
}
