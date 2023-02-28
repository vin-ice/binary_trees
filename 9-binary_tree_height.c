#include "binary_trees.h"

/**
 * branch_height - returns the height of the branch
 * @branch: branch tree
 * Return: 0 if null
*/
int branch_height(binary_tree_t *branch)
{
    size_t l_len = 0, r_len = 0;
    if (branch == NULL)
        return (0);
    l_len = branch_height(branch->left);
    r_len = branch_height(branch->right);

    return (((l_len < r_len) ? r_len : l_len) + 1);
}

/**
 * binary_tree_height - measures height of a binary tree
 * @tree: Pointer to root node of the 
 * Return: 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t l_height = 0, r_height;

    if (tree == NULL)
        return (0);
    l_height = branch_height(tree->left);
    r_height = branch_height(tree->right);
    return ((l_height > r_height) ? l_height : r_height);
}