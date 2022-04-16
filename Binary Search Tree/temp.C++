#include<iostream>
using namespace std;
class Binary_search_tree
{
    int key;
    Binary_search_tree *left, *right;
    public: 
         Binary_search_tree(); //Default Constructor
         Binary_search_tree(int); //Parameterized Constructor
         Binary_search_tree* Insert(Binary_search_tree*,int);
         void Inorder(Binary_search_tree*);
}*ptr;

/* Default Constructor */
Binary_search_tree::Binary_search_tree() : key(0), left(NULL), right(NULL) { }

// Parameterized Constructor 
Binary_search_tree :: Binary_search_tree(int value) 
{
   key = value;
   left = right = NULL;
}

// Insert method
Binary_search_tree* Binary_search_tree :: Insert(Binary_search_tree* root, int value)
{
    if(root == NULL)
    {
        return new Binary_search_tree(value);
    }    
    else if(value > root->key)
    {
        root->right = Insert(root->right,value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    
    return root;
}

// Inorder Traversal 
void Binary_search_tree::Inorder(Binary_search_tree *root)
{
    if(root == NULL)
    {
        return;
    }
    else 
    {
        Inorder(root->left);
        cout << root->key << endl;
        Inorder(root->right);
    }
}

int  main()
{
    int count,key;
    cout << "How many keys you are going to Enter : ";
    cin >> count;
    Binary_search_tree *root = NULL;

    Binary_search_tree bst; // Creating an object;
    root = bst.Insert(root,10);
    cout << "Enter %d keys : ",count;
    for(int i=1;i<=count;i++)
    {
        cin >> key;
        bst.Insert(root,key);
    }

    cout << "\n Inorder Traversal of the Tree : \n";
    bst.Inorder(root);
    return 0;
}