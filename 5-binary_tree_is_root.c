#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if given node is root
 * @node: Pointer to node
 * Return: 1 if node else 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node)
        if (!node->parent)
            return (1);
    return (0);
}