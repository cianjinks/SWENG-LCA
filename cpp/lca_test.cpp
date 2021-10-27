#include <gtest/gtest.h>

#include "lca.h"

/* Test binary tree. */
std::vector<Node *> buildTestBinaryTree()
{
    Node *root = new Node(0);
    root->nodes.push_back(new Node(2));                               // root->left = new Node(2);
    root->nodes[0]->nodes.push_back(new Node(8));                     // root->left->left = new Node(8);
    root->nodes[0]->nodes.push_back(new Node(5));                     // root->left->right = new Node(5);
    root->nodes[0]->nodes[1]->nodes.push_back(new Node(6));           // root->left->right->left = new Node(6);
    root->nodes[0]->nodes[1]->nodes.push_back(new Node(7));           // root->left->right->right = new Node(7);
    root->nodes.push_back(new Node(1));                               // root->right = new Node(1);
    root->nodes[1]->nodes.push_back(new Node(9));                     // root->right->right = new Node(9);
    root->nodes[1]->nodes[0]->nodes.push_back(new Node(3));           // root->right->right->right = new Node(3);
    root->nodes[1]->nodes[0]->nodes[0]->nodes.push_back(new Node(4)); // root->right->right->right->right = new Node(4);

    std::vector<Node *> top_parents;
    top_parents.push_back(root);
    return top_parents;
}

/* DAGS can have multiple "roots" so return value is vector of roots. */
std::vector<Node *> buildTestDAG()
{
    /* https://en.wikipedia.org/wiki/File:Tred-G.svg */
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    a->nodes.push_back(b);
    a->nodes.push_back(d);
    a->nodes.push_back(c);
    a->nodes.push_back(e);
    b->nodes.push_back(d);
    c->nodes.push_back(d);
    c->nodes.push_back(e);
    d->nodes.push_back(e);

    /* Added d and e to have extra parent 0. */
    Node *extra = new Node(0);
    extra->nodes.push_back(d);
    extra->nodes.push_back(e);

    std::vector<Node *> top_parents;
    top_parents.push_back(a);
    top_parents.push_back(extra);
    return top_parents;
}

/* Unit Tests. */
TEST(LCATest, SimpleTests)
{
    /* No strange edge cases. */
    std::vector<Node *> root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 6, 7), 5);
    EXPECT_EQ(findLCA(root, 8, 7), 2);
    EXPECT_EQ(findLCA(root, 8, 3), 0);
    EXPECT_EQ(findLCA(root, 9, 6), 0);
}

TEST(LCATest, NullTests)
{
    /* Root null. */
    Node *root = NULL;
    std::vector<Node *> top = {root};
    EXPECT_EQ(findLCA(top, 100, 2), -1);
    EXPECT_EQ(findLCA(top, 20, 1), -1);
}

TEST(LCATest, SameTests)
{
    /* Check for LCA of same node with itself. */
    std::vector<Node *> root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 9, 9), 9);
    EXPECT_EQ(findLCA(root, 6, 6), 6);
    EXPECT_EQ(findLCA(root, 4, 4), 4);

    /* Note: Binary tree will not contain duplicate keys. No need to test. */
}

TEST(LCATest, ParentTests)
{
    /* If 3 is the parent node of 4 what is the LCA? I would say 3 is. */
    std::vector<Node *> root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 3, 4), 3);
    EXPECT_EQ(findLCA(root, 9, 3), 9);
}

TEST(LCATest, DagTests)
{
    std::vector<Node *> top_parents = buildTestDAG();
    EXPECT_EQ(findLCA(top_parents, 3, 4), 3); // b and c
    // Parent Tests
    EXPECT_EQ(findLCA(top_parents, 1, 2), 1); // a and b
    EXPECT_EQ(findLCA(top_parents, 4, 5), 4); // d and e, not 0 because d is parent of e
    // Same Test
    EXPECT_EQ(findLCA(top_parents, 4, 4), 4); // d and d
}