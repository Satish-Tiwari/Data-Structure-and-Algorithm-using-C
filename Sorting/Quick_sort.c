#include<stdio.h>
#include<conio.h>
int Quick_sort(int a[],int l);
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

    Quick_sort(a,l);

    printf("\n Sorted Array: ");
    for(i=0;i<l;i++)
    printf(" %d",a[i]);
    getch();
}
int  Quick_sort(int a[],int l)
{
   int i,left=0,right=l;
   int lock=right;
   if(a[left]<a[lock]){
   right=right-1;
   lock=lock-1; }
   else if(a[left]>a[lock])
   {
       int temp=a[left];
       a[left]=a[lock];
       a[lock]=temp;
       if(lock==right)
       lock=left;
       else if(lock==left)
       lock=right;
   }


}
