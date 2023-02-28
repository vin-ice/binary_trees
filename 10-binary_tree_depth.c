#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of a node
 * in a binary tree
 * @tree: Pointer to the node
 * Return: 0 if tree is null
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL)
        return (0);
    depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
    return (depth);
}