#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance
 * factor of a binary tree
 * @tree: Pointer to root node of tree
 * Return: 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
    int l_height, r_height;

    if (tree == NULL)
        return (0);
    l_height = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
    r_height = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
    return (l_height - r_height);
}