#include<stdio.h>
#include<stdlib.h>
struct node
{
    int v;
    struct node *next;
}*adj[10];
int no_of_vert;
void create(void)
{
    int _n;
    struct node *newnode,*ptr;
    printf("Enter the no. of vertices present in the graph: ");
    scanf("%d",&no_of_vert);
    for(int i=0;i<no_of_vert;i++)
    {
        adj[i]=NULL;
    }
    for(int i=0;i<no_of_vert;i++)
    {
    printf("Enter the no. of  neighbour of %d: ",i);
    scanf("%d",&_n);
    printf("Enter neighbours: ");
    for(int j=0;j<_n;j++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->v);
        newnode->next = NULL;
        if(adj[i]==NULL)
        {
            adj[i]=newnode;
        }
        else
        {
            ptr = adj[i];
            while(ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
    }
}
void display(void)
{
    struct node *ptr;
    printf("\n The linked representation of the Graph : ---\n");
    for(int i=0;i<no_of_vert;i++)
    {
        printf("%d-->",i);
        ptr=adj[i];
        while(ptr!=NULL)
        {
            printf(" %d",ptr->v);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
int  main()
{
    create();
    display();
    return 0;
}