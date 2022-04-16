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
    int opt;
    printf("\tBinary Search Tree Program");
    while(1)
    {
        printf("\n1.Creation of Binary Search Tree.");
        printf("\n2 Inorder Traversal of the Binary SearchTree.");
        printf("\nEnter option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: Creation();
                    break;
            case 2: printInorder(root);
                    break;  
            default: exit(0);                               
        }
    }
    return 0;
}
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
