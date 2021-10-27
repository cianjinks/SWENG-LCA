#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct Node
{
    int key;
    std::vector<Node *> nodes;

    Node(int key);
};

std::vector<Node *> buildTestBinaryTree();
std::vector<Node *> buildTestDAG();
void findAncestors(Node *root, int k, std::vector<Node *> &r_ancestors);
void findLCA_recursive(Node *root, int k1, int k2, Node *&result);
int findLCA(std::vector<Node *> top_parents, int k1, int k2);