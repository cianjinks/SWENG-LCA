#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node *left, *right;

    Node(int key);
};

Node *buildTestTree1();
void deleteTree(Node* root);
bool findPath(Node *root, std::vector<int> &path, int k);
int findLCA(Node *root, int k1, int k2);