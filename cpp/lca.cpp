#include "lca.h"

Node::Node(int key) : key(key) {}

/* Is k reachable from root? */
bool dfs(Node *root, int k)
{
    // DFS
    std::stack<Node *> s;
    std::vector<Node *> discovered;
    s.push(root);
    while (!s.empty())
    {
        Node *v = s.top();
        s.pop();
        if (std::find(discovered.begin(), discovered.end(), v) == discovered.end())
        {
            discovered.push_back(v);
            for (Node *w : v->nodes)
            {
                s.push(w);
            }
        }
    }
    for (Node *n : discovered)
    {
        if (n->key == k)
        {
            return true;
        }
    }
    return false;
}

void findLCA_recursive(Node *root, int k1, int k2, Node *&result)
{
    if (root)
    {
        if (dfs(root, k1) && dfs(root, k2))
        {
            result = root;
            for (Node *n : root->nodes)
            {
                findLCA_recursive(n, k1, k2, result);
            }
        }
    }
}

int findLCA(std::vector<Node *> top_parents, int k1, int k2)
{
    if (k1 == k2)
    {
        return k1;
    }

    Node *result = NULL;
    for (Node *n : top_parents)
    {
        findLCA_recursive(n, k1, k2, result);
        if (result != NULL)
        {
            return result->key;
        }
    }
    return -1;
}