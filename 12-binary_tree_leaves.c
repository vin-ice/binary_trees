#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a
 *  binary tree
 * @tree: Pointer to root node of the tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t child = 0;
    
    if (tree == NULL)
        return (0);
    child = binary_tree_leaves(tree->left) +
            binary_tree_leaves(tree->right);
    if (child == 0)
        return (1);
    return (child);
}