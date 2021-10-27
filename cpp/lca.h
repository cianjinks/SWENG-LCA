#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct Node
{
    int key;
    Node *left, *right;

    Node(int key);
};

struct DAGNode
{
    int key;
    std::vector<DAGNode *> nodes;

    DAGNode(int key);
};

Node *buildBinaryTestTree();
void deleteBinaryTree(Node *root);
bool findPath(Node *root, std::vector<int> &path, int k);
int findLCA(Node *root, int k1, int k2);

std::vector<DAGNode *> buildTestDAG();
void deleteDAG(DAGNode *root);
void findAncestors(DAGNode *root, int k, std::vector<DAGNode *> &r_ancestors);
int findDAGLCA(std::vector<DAGNode *> top_parents, int k1, int k2);