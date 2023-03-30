#include <iostream>
#include <queue>
using namespace std;

struct Node 
{
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*) malloc(sizeof (struct Node));
    if (temp == NULL)
    {
        cout << "Can not allocate memory";
    }
    else
    {
        temp->key = item;
        temp->left = temp->right = NULL;
    };
    return temp;
}

struct Node* insert(struct Node* node, int key)
{
    if(node == NULL)
    {
        return newNode(key);
    }

    if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    return node;
}

void postOrderTraversal(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    cout << root->key << " ";
    postOrderTraversal(root->right);
    
}

int height(struct Node* node)
{
    if(node == NULL)
    {
        return 0;
    }
    int l_height = height(node->left);
    int r_height = height(node->right);

    if( l_height > r_height)
    {
        return l_height + 1;
    }
    else return r_height + 1;
}

bool search(struct Node* root, int key)
{
    if (root == NULL)
    {
        // cout << "Key doesn't exist!";
        return false;
    }
    if (root->key == key)
    {
        // cout << "Exist";
        return true;
    }
    bool res = false;

    if(root->key < key)
    {
        res =  search(root->right, key);
    }
    else 
    {
        res = search(root->left, key);
    }
    return res;
}

struct Node* minLeftValueNode(struct Node* node)
{
    struct Node* current = node;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
};

struct Node* deleteNode(struct Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    if(key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if ( key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else 
    {
        //No child
        if(root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        //One child
        else if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if( root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        //Two children
        struct Node* temp = minLeftValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void BFS(Node *root)
{
    if (root == NULL) return;
 
    // Create an empty queue for
    // level order traversal
    queue<Node *> q;
     
    // to store front element of
    // queue.
    Node *curr;
 
    // Enqueue Root and NULL node.
    q.push(root);
    q.push(NULL);
 
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
         
        // condition to check
        // occurrence of next
        // level.
        if (curr == NULL)
        {
           q.push(NULL);
           cout << "\n";
        }
         
        else {
             
            // pushing left child of
            // current node.
            if(curr->left)
            {
                q.push(curr->left);
            }
             
            // pushing right child of
            // current node.
            if(curr->right)
            {
                q.push(curr->right);
            }
             
            cout << curr->key << " ";
        }
    }
};
 

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // postOrderTraversal(root);
    BFS(root);
    cout << endl;
    // cout << height(root);
    // cout << search(root, 700);
    deleteNode(root, 70);
    BFS(root);

    return 0;
}
