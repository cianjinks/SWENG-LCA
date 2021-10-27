#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node *left, *right;

    Node(int key);
};

Node *buildBinaryTestTree();
Node *buildTestDAG();
void deleteBinaryTree(Node *root);
bool findPath(Node *root, std::vector<int> &path, int k);
int findLCA(Node *root, int k1, int k2);