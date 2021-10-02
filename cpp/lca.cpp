#include "lca.h"

Node::Node(int key)
    : key(key)
{
    left = nullptr;
    right = nullptr;
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