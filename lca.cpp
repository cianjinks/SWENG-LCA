#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node *left, *right;

    Node(int key) : key(key)
    {
        left = nullptr;
        right = nullptr;
    }
};

Node *buildTree()
{
    Node *root = new Node(0);
    root->left = new Node(2);
    root->left->left = new Node(8);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right = new Node(1);
    root->right->right = new Node(9);
    root->right->right->right = new Node(3);
    root->right->right->right->right = new Node(4);
    return root;
}

bool findPath(Node *root, std::vector<int> &path, int k)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->key);

    if (root->key == k)
    {
        return true;
    }

    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
    {
        return true;
    }

    path.pop_back();

    return false;
}

int findLCA(Node *root, int k1, int k2)
{
    std::vector<int> p1, p2;
    if (!findPath(root, p1, k1) || !findPath(root, p2, k2))
    {
        return -1;
    }

    int i = 0;
    for (; i < p1.size() && i < p2.size(); i++)
    {
        if (p1[i] != p2[i])
        {
            break;
        }
    }

    return p1[i - 1];
}

int main()
{
    Node *root = buildTree();
    int k1 = 6, k2 = 7;
    std::cout << "LCA of " << k1 << " and " << k2 << " is " << findLCA(root, k1, k2) << "!" << std::endl;
}