#include<stdio.h>
#include<conio.h>
int Redix_sort(int a[],int l);
int main()
{
    int a[50],l,i;
    printf("\n Enter the length of the Array: ");
    scanf("%d",&l);
    printf("\n Enter the array: ");
    for(i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }

    Redix_sort(a,l);

    printf("\n Sorted Array: ");
    for(i=0;i<l;i++)
    printf(" %d",a[i]);
    getch();
}
int Redix_sort(int a[],int l)
{

}
