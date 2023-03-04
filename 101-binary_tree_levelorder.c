#include "binary_trees.h"

/**
 * _traverse_level - traveses nodes at given level and
 * applies function
 * @tree: tree
 * @func: Operation to apply on nodes visited
 * @level: current level
*/
void _traverse_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
    if (level == 1)
        func(tree->n);
    else
    {
        _traverse_level(tree->left, func, level - 1);
        _traverse_level(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_levelorder - traverses tree using level-order traversal
 * @tree: Pointer to root node of the tree
 * @func: pointer to a funstion to be called
 * 
 * Return: NULL if tree/func is NULL
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, level;

    if (!tree || !func)
        return;
    
    height = binary_tree_height(tree) + 1;

    for (level = 1; level <= height; level++)
        _traverse_level(tree, func, level);    
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
    l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
    return ((l_height > r_height) ? l_height : r_height);
}