#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL,*ptr;
/*Function for Creation Operation of Binary Search Tree*/
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
                if(newnode->data < ptr->data)
                ptr=ptr->left;
                else 
                ptr=ptr->right;
            }
            if(newnode->data < pre->data)
            pre->left=newnode;
            else 
            pre->right=newnode;
        }
    }
}
/*Function for Inorder Traversal of Binary Search Tree*/
void In_order(struct node *node)
{
  if (node == NULL) 
          return;
    
    /* first recur on left child */
    In_order(node->left); 

    /* then print the data of node */
    printf("%d ", node->data);   
  
    /* now recur on right child */
    In_order(node->right);
}
/*Function for Preorder Traversal of Binary Search Tree*/
void Pre_order(struct node *node)
{
  if(node==NULL)
  return;
    
    /*First print the data of node*/
    printf("%d ", node->data);

    /* then recur on left child */
    Pre_order(node->left);

    /* now recur on right child */
    Pre_order(node->right);
}
/*Function for Postorder Traversal of Binary Search Tree*/
void Post_order(struct node *node)
{
    if(node==NULL)
    return;
    
    /* first recur on left child */
    Post_order(node->left);

    /* then recur on right child */
    Post_order(node->right);

    /*First print the data of node*/
    printf("%d ", node->data); 
}
int main()
{
    int opt;
    char  ch;
    printf("\n <<<Implementation of Binary Search Tree>>>");
    do
    {
    printf("\n\n 1. Creation");
    printf("\n 2. Traversal");
    printf("\n 3.Exit from the Program");
    printf("\n\t Enter option: ");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: Creation();
                break;
        case 2:
             {
                 printf("\n Enter any of the following option:-");
                 printf("\n\t A. Inorder Traversal");
                 printf("\n\t B. Preorder Traversal");
                 printf("\n\t C. Postorder Traversal");
                 fflush(stdin);//Use to clear the input buffer.
                 printf("\n\t\t Enter any Option: ");
                 scanf("%c",&ch);
                 switch((char)ch)
                 {
                    case 'A': printf("\n Inorder Traversal of the Binary Search Tree:--\n\t");
                              In_order(root);
                              break;
                    case 'B': printf("\n Preorder Traversal of the Binary Search Tree:--\n\t");
                              Pre_order(root);
                              break;
                    case 'C': printf("\n Postorder Traversal of the Binary Search Tree:--\n\t");
                              Post_order(root);
                              break;
                    default: printf("\n\t Invalid Option of Treaversal.");                
                 }
                 break;
             }
        case 3: exit(0);
        default: printf("Invalid Option");                     
    }
    }
    while(1);
    return 0;
}