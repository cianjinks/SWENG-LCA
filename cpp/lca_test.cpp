#include <gtest/gtest.h>

#include "lca.h"

/* Free memory of a binary tree. */
void deleteBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    delete root;
}

/* Some test binary trees. */
Node *buildTestBinaryTree()
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

Node *buildTestDAG()
{
}

/* Unit Tests. */
TEST(LCATest, SimpleTests)
{
    /* No strange edge cases. */
    Node *root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 6, 7), 5);
    EXPECT_EQ(findLCA(root, 8, 7), 2);
    EXPECT_EQ(findLCA(root, 8, 3), 0);
    EXPECT_EQ(findLCA(root, 9, 6), 0);
    deleteBinaryTree(root);
}

TEST(LCATest, NullTests)
{
    /* Root null. */
    Node *root = NULL;
    EXPECT_EQ(findLCA(root, 100, 2), -1);
    EXPECT_EQ(findLCA(root, 20, 1), -1);
}

TEST(LCATest, SameTests)
{
    /* Check for LCA of same node with itself. */
    Node *root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 9, 9), 9);
    EXPECT_EQ(findLCA(root, 6, 6), 6);
    EXPECT_EQ(findLCA(root, 4, 4), 4);
    deleteBinaryTree(root);

    /* Note: Binary tree will not contain duplicate keys. No need to test. */
}

TEST(LCATest, ParentTests)
{
    /* If 3 is the parent node of 4 what is the LCA? I would say 3 is. */
    Node *root = buildTestBinaryTree();
    EXPECT_EQ(findLCA(root, 3, 4), 3);
    EXPECT_EQ(findLCA(root, 9, 3), 9);
    deleteBinaryTree(root);
}