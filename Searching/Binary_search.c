#include<stdio.h>
#include<conio.h>
int Binary_Search(int a[],int n,int key);
int main()
{
    int a[100],n,i,key,index;
    printf("\n Binary Search Algorithm Program--\n\t Note:-'Enter Data in Ordered form, Either in 'Ascending Order' or in 'Descending Order' ' \n");
    printf("\n Enter no. of Element: ");
    scanf("%d",&n);
    printf("\n Enter %d Element: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n Enter Element are:  ");
    for(i=0;i<n;i++)
       printf("%d  ",a[i]);
     printf("\n Enter the Element that you want to search: ");
     scanf("%d",&key);
     index=Binary_Search(a,n,key);
     if(index==-1)
        printf("\n Element not found.");
     else
        printf("\n The Element found at Position=%d",index+1);
     getch();
}
int Binary_Search(int a[],int n,int key)
{
    int i=0,j=n-1,mid;
    mid=(i+j)/2;

    /* If the Enter data is in Ascending Order-- */
    if(a[i]<a[i+1] && a[i+1]<a[i+2])
    {
     while(a[mid]!=key && i<=j)
      {
       if(a[mid]<key)
            i=mid+1;
       else
         j=mid-1;
       mid=(i+j)/2;
      }
    if(i<=j)
       return(mid);
    else
        return(-1);
    }

    /* If the enter data is not in Ascending order.(That is, in Descending Order.)--*/
    else
    {
      while(a[mid]!=key && j>=i)
      {
       if(a[mid]>key)
            i=mid+1;
       else
         j=mid-1;
       mid=(i+j)/2;
      }
    if(j>=i)
       return(mid);
    else
        return(-1);
    }
}


