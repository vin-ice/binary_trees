#include "binary_trees.h"



/**
 * binary_trees_ancestor - Finds the lowest
 *  common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * 
 * Return: Pointer to the lowest common ancestor node
 *  else NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    size_t depth_f, depth_s; 
    
    if (!first || !second)
        return (NULL);

    depth_f = binary_tree_depth(first);
    depth_s = binary_tree_depth(second);
    /**level the nodes*/
    for (; depth_f > depth_s; first = first->parent, depth_f--)
        ;
    for (; depth_f < depth_s; second = second->parent, depth_s--)
        ;
        
    while (first && second)
    {
        if (first == second)
            return ((binary_tree_t *) first); /**either*/
        first = first->parent;
        second = second->parent;
    }
    return ((binary_tree_t *) first);
}

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