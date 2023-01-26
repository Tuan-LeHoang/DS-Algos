#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    char value;
    vector<Node*> children;
};

Node* new_node(char value)
{
    Node* temp = new Node();
    temp->value = value;
    temp->children = {};
    return temp;
};

void preoder_traversal(Node* root)
{
    if(root->children.size() == 0)
    {
        cout << root->value << " ";
        return;
    }

    cout << root->value << " ";

    int number_of_children_of_current_node = root->children.size();
    for(int i = 0; i< number_of_children_of_current_node; i++)
    {
        Node* temp = root->children[i];
        preoder_traversal(temp);
    }
}

void postoder_traversal(Node* root)
{
    if(root->children.size() == 0)
    {
        cout << root->value << " ";
        return;
    }

    int number_of_children_of_current_node = root->children.size();
    for(int i = 0; i< number_of_children_of_current_node; i++)
    {
        Node* temp = root->children[i];
        postoder_traversal(temp);
    }

    cout << root->value << " ";
}

void inoder_traversal(Node* node)
{
    if(node->children.size() == 0)
    {
        cout << node->value << " ";
        return;
    }

    Node* left_most_child = node->children[0];
    inoder_traversal(left_most_child);

    cout << node->value << " ";

    for(int i = 1; i < node->children.size(); i++)
    {
        Node* temp = node->children[i];
        inoder_traversal(temp);
    }
}

void breadth_first_search(Node* node)
{
    if(node->children.size() == 0)
    {
        cout << node->value << " ";
        return;
    }

    cout << node->value << endl;

    queue<Node*> q;
    q.push(node);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        for(int i = 0 ; i < temp->children.size(); i++)
        {
            cout << temp->children[i]->value << " ";
            q.push(temp->children[i]);
        }
        cout << endl;
    }

}


int main()
{
    Node* root = new_node('b');
    root->children.push_back(new_node('e'));
    root->children.push_back(new_node('f'));

    root->children[0]->children.push_back(new_node('j'));
    root->children[0]->children.push_back(new_node('k'));

    root->children[0]->children[1]->children.push_back(new_node('n'));
    root->children[0]->children[1]->children.push_back(new_node('o'));
    root->children[0]->children[1]->children.push_back(new_node('p'));

    // preoder_traversal(root);
    // postoder_traversal(root);
    // inoder_traversal(root);
    breadth_first_search(root);

    return 0;
}