#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> output;
vector<int> leftView(Node *root)
{
    // // Your code here
    // vector<int> output;
    // Node *temp = new Node(0);
    // temp = root;
    // if (root != nullptr)
    // {
    //     while (temp != nullptr)
    //     {
    //         output.push_back(temp->data);
    //         if (temp->left == nullptr && temp->right != nullptr)
    //             temp = temp->right;
    //         else
    //             temp = temp->left;
    //     }
    // }
    // return output;

    if (root != nullptr)
    {
        output.push_back(root->data);
        if (root->left == nullptr && root->right != nullptr)
            leftView(root->right);
        else
            leftView(root->left);
    }
    return output;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    vector<int> mine;
    mine = leftView(root);

    for (auto i : mine)
        cout << i << " ";
}
