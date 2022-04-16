#include<iostream>
using namespace std;
class node
{
   int data;
   node *left;
   node *right;
   public: 
         node();
         node(int);
         node* Insert(node*, int);
         node* Delete(node*, int);
         node* minvalue(node*);
         void Inorder(node*);
}*root = NULL;

// Default Constructor
node :: node() : data(0), left(NULL), right(NULL) { }

// parameterized constructor
node :: node(int value)
{
    data = value;
    left = right = NULL;
}

// Insert Operation
node* node::Insert(node* root, int value)
{
    if(root == NULL)
    {
        return  new node(value);
    }
    else if(value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        
        root->right = Insert(root->right, value);
    }
    return root;
}

// Inorder Traversal
void node :: Inorder(node *root)
{
    if(root == NULL)
    return;
    else
    {
        Inorder(root->left);
        cout << root->data << endl;
        Inorder(root->right);
    }
}

// Deletion operation

// Min value
node* node::minvalue(node* root)
{
    node *temp = root;
    while(temp->left != NULL)
    temp  = temp->left;

    return temp;
}

node* node :: Delete(node *root, int value)
{
    if(root == NULL) { return root ;}
    else if(value < root->data)
    {
        root->left = Delete(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = Delete(root->right, value);
    }
    else if(value == root->data)
    {
        if(root->left == NULL && root->right == NULL) // if the node is leaf node;
        {
            free(root);
            return NULL;
        }
        if(root->left == NULL)   // if node has one child;
        {
            node *ptr = root->left;
            free(root);
            return ptr;
        }
        if(root->right == NULL)   // if node has one child;
        {
            node *ptr = root->left;
            free(root);
            return ptr;
        }
        // node with two child get Inorder Successor....
        node *ptr = minvalue(root->right);

        // copy the ptr into root 
        root->data = ptr->data;

        // delete ptr
        root->right = Delete(root->right, ptr->data);

    }
}

//Driver Code
int main()
{
    int count,key;
    cout << "How many keys you are going to Enter : ";
    cin >> count;
   
    node  bst; // Creating an object;
  //  root = bst.Insert(root,10);
    cout << "Enter " << count << " node : ";
    for(int i=1;i<=count;i++)
    {
        cin >> key;
        if(i==1)// it means for first element.......
        root = bst.Insert(root,key);
        else{
        bst.Insert(root,key);
        }
    }
        
    cout << "\n Inorder Traversal of the Tree : \n";
    bst.Inorder(root);

    cout << "\n Deletion of the Binary search Tree : \n";
    cout << " Enter the key, that you want to delete : ";
    cin >> key;
    bst.Delete(root,key);

    bst.Inorder(root);

    return 0;
}