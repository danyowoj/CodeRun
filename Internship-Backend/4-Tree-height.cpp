#include <iostream>

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

int getHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int main()
{
    Node *root = nullptr;
    int num;
    while (std::cin >> num && num != 0)
        root = insert(root, num);
    std::cout << getHeight(root) << std::endl;

    return 0;
}
