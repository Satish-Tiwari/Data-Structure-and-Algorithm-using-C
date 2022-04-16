#include<stdio.h>
#include<conio.h>
int sequential_search(int array[],int n,int key)
{
    int i=0;
    while(i<n && key!=array[i])
    {
        i++;
    }
    if(i<n)
        return(i);
    else
        return(-1);
}
int main(void)
{
    printf("\n Program for Sequential Search.--");
    int array[100],i,n,key,index;
    printf("\n Enter no. of the Element: ");
    scanf("%d",&n);
    printf("\n Enter %d Element: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("\n The Element in array are: ");
    for(i=0;i<n;i++)
        printf("%d  ",array[i]);
    printf("\n Enter element that you want to search: ");
    scanf("%d",&key);
    index=sequential_search(array,n,key);
    if(index==-1)
        printf("\n Element not found.");
    else
        printf("\n Element found at Position=%d",index+1);
    getch();
}
