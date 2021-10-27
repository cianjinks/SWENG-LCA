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

DAGNode::DAGNode(int key) : key(key) {}

/* Is k reachable from root? */
bool dfs(DAGNode *root, int k)
{
    // DFS
    std::stack<DAGNode *> s;
    std::vector<DAGNode *> discovered;
    s.push(root);
    while (!s.empty())
    {
        DAGNode *v = s.top();
        s.pop();
        if (std::find(discovered.begin(), discovered.end(), v) == discovered.end())
        {
            discovered.push_back(v);
            for (DAGNode *w : v->nodes)
            {
                s.push(w);
            }
        }
    }
    for (DAGNode *n : discovered)
    {
        if (n->key == k)
        {
            return true;
        }
    }
    return false;
}

void findAncestors(DAGNode *root, int k, std::vector<DAGNode *> &r_ancestors)
{
    if (dfs(root, k))
    {
        r_ancestors.push_back(root);
        for (DAGNode *n : root->nodes)
        {
            findAncestors(n, k, r_ancestors);
        }
    }
}

int findDAGLCA(std::vector<DAGNode *> top_parents, int k1, int k2)
{
    if (k1 == k2)
    {
        return k1;
    }

    int lowest = -1;
    for (DAGNode *parent : top_parents)
    {

        /* Get all ancestors of k1 and k2. */
        std::vector<DAGNode *> ancestors_k1;
        std::vector<DAGNode *> ancestors_k2;
        findAncestors(parent, k1, ancestors_k1);
        findAncestors(parent, k2, ancestors_k2);

        /* Find lowest common. */
        for (DAGNode *n : ancestors_k1)
        {
            if (std::find(ancestors_k2.begin(), ancestors_k2.end(), n) != ancestors_k2.end())
            {
                if (n->key < lowest || lowest == -1)
                {
                    lowest = n->key;
                }
            }
        }
    }
    return lowest;
}
