#include<stdio.h>
#include<conio.h>
int main()
{
    int spmatrix[20][20],m,n;
    int i,j;  //for loops.
    printf("\n\t <--Sparse Matrix Program-->");
    printf("\n How many rows present in Sparse Matrix: ");
    scanf("%d",&m);
    printf("How many columns present in Sparse Matrix: ");
    scanf("%d",&n);
    printf("\n Enter the value in to Sparse matrix in %d*%d format:\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&spmatrix[i][j]);
        }
    }
    printf("\n The value Inserted into sparse matrix are:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",spmatrix[i][j]);
        }
        printf("\n");
    }
    /* We are going to Count the Non-Zero element in Sparse matrix. */
    int count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(spmatrix[i][j]!=0)
                count++;
        }
    }
    printf("\n Total number of Non-Zero element in Sparse matrix are: %d \n",count);

    /* we can store the Non-Zero element of sparse matrix in a New matrix which has 3 rows--
       1. Row number.
       2. Column number.
       3. Element Value.
       Number of Column depend upon the No. of Non-Zero Elements.

       Note:- "But in this program New matrix have 3 columns and rows depends upon No. of non-Zero Elements." */

    printf("\n We can store the Non-zero Element of Sparse matrix in a New matrix with following format--\n\n");

    int com_matrix[m][count],k=1;
    com_matrix[0][0]=m;
    com_matrix[1][0]=n;
    com_matrix[2][0]=count;

    printf("Rows number\tColumn number\tElement value\n");


    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(spmatrix[i][j]!=0)
            {
                com_matrix[0][k]=i;
                com_matrix[1][k]=j;
                com_matrix[2][k]=spmatrix[i][j];
                printf("%d \t\t",i);
                printf("%d \t\t",j);
                printf("%d \t\n",spmatrix[i][j]);
                k++;
            }
        }
    }
    getch();
}
