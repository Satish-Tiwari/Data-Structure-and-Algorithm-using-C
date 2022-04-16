#include<stdio.h>
void selection_sort(int a[],int n);
int smallest(int a[],int k, int n);
int main(){

   // Program for Selection Sort
   printf("\t <<-- Program for Selection sort--> ");
   int a[30],i,j,n;
   printf("\n The Number of Elements:");
   scanf("%d",&n);
   printf("\n Enter the Elements into the Array:");
   for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }

    selection_sort(a,n);
    printf("\n The sorted array is: ");
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }

  getch();
}
void selection_sort(int a[],int n)
{
  int k,pos,temp;
  for(k=0;k<n;k++)
  {
    pos=smallest(a,k,n);
    temp=a[k];
    a[k]=a[pos];
    a[pos]=temp;
  }

}
int smallest(int a[],int k, int n)
{
  int pos=k,small=a[k],i;
  for(i=k+1;i<n;i++)
  {
    if(a[i]<small)
    {
      small=a[i];
      pos=i;
    }
  }
  return pos;
}
