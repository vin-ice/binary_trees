#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree
 * using post-order traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each
 * node
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        if (tree->left)
            binary_tree_postorder(tree->left, func);
        if (tree->right)
            binary_tree_postorder(tree->right, func);
        func(tree->n);
    }
}