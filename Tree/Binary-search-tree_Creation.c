/*Program to Create a Binary Search Tree*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL,*ptr;
void Creation();
void printInorder(struct node *node);
void main()
{
    printf("\t Creation operation of Binary Search Tree.\n");
    Creation();
    printf("\t Inorder Traversal of Created Binary Search Tree:-\n\t ");
    printInorder(root);            
    getch();
}
/*Function to create a Binary Search Tree.*/
void Creation()
{
    struct node *newnode,*pre;
    int n,j;
    printf("Enter the number of Element: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter %d element: ",i);
        scanf("%d",&newnode->data);
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            ptr=root;
            while(ptr!=NULL)
            {    
                pre=ptr;
                if(newnode->data<ptr->data)
                ptr=ptr->left;
                else
                ptr=ptr->right;
            }
            if(pre->data>newnode->data)
            pre->left=newnode;
            else
            pre->right=newnode;
        }
    }
}
/*Function to print Inorder Traversal of the Binary Search Tree.*/
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(node->left); 
  
     /* then print the data of node */
     printf("%d ", node->data);   
  
     /* now recur on right child */
     printInorder(node->right); 
} 