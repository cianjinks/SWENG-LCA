#include <gtest/gtest.h>

#include "lca.h"

/* Free memory of a binary tree. */
void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

/* Some test binary trees. */
Node *buildTestTree1()
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

/* Unit Tests. */
TEST(LCATest, SimpleTests)
{
    /* No strange edge cases. */
    Node *root = buildTestTree1();
    EXPECT_EQ(findLCA(root, 6, 7), 5);
    EXPECT_EQ(findLCA(root, 8, 7), 2);
    EXPECT_EQ(findLCA(root, 8, 3), 0);
    EXPECT_EQ(findLCA(root, 9, 6), 0);
    deleteTree(root);
}

TEST(LCATest, ParentTests)
{
    /* If 3 is the parent node of 4 what is the LCA? I would say 3 is. */
    Node *root = buildTestTree1();
    EXPECT_EQ(findLCA(root, 3, 4), 3);
    EXPECT_EQ(findLCA(root, 9, 3), 9);
    deleteTree(root);
}