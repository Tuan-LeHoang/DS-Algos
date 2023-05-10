#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class Node
{
    public:
        int key;
        Node *left;
        Node *right;
        int height;
};

int height(Node *N)
{
    if( N == NULL) return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node *rightRotate(Node* y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    //Rotate
    x->right = y;
    y->left = T2;
    //Update heights of tree
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    //Rotate
    y->left = x;
    x->right = T2;
    //Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N)
{
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    //1. Normal BST insertion. 
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if ( key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
    
    //2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));
    
    //3. Get the balance factor => check unbalanced node. 
    int balance  = getBalance(node);

    //left left case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);

    //right right caes
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    //left right case
    if(balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //right left case
    if(balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root)
{
    if(root == NULL) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In - Print 2D ra console
void print2DUtil(Node* root, int space){
    if (root == NULL)
    return;
    space += COUNT;
    
    print2DUtil(root->right, space);
    cout << endl;
    
    for (int i = COUNT; i < space; i++)
    cout << " ";
    cout << root->key << " (" << root->height << ") " << "\n";
    
    print2DUtil(root->left, space);
}
 
Node* minValueNode(Node* node)
{
    Node* current = node;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key)
{
    //1. Normal BST deletetion.
    if(root = NULL)
        return root;
    if( key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if((root->left == NULL || root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    //2. Rebalance
    if(root == NULL)
        return root;
    
    //Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));
    //Get balance
    int balance  = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if(balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if(balance < -1 &&getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    Node* root  = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    // preOrder(root); 
    // 30 20 10 25 40 50 
    print2DUtil(root,1);
    deleteNode(root,30);
    print2DUtil(root,1);

    return 0;
}
