#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: Pointer to node in question
 * Return: 1 if leaf else 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node)
    {
        if (!node->left && !node->right)
            return (1);
    }
    return (0);
}