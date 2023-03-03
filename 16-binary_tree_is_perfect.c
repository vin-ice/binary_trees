#include "binary_trees.h"

/**
 * get_a_depth - returns a depth to work with (left biased)
 * @tree: tree to get depth from
 * Return: depth
*/
size_t get_a_depth(const binary_tree_t *tree)
{
	if (tree->left)
		return (1 + get_a_depth(tree->left));
	return (0);
}

/**
 * _venture - ventures tree and compares height and levels
 * @tree: tree to venture
 * @depth: ideal depth to venture
 * @level: level currently venturing
*/
size_t _venture(const binary_tree_t *tree, size_t depth, int level)
{
	if (!tree->left && !tree->right)
		return (level == (int) depth ? 1 : 0);
	if (!tree->left || !tree->right)
		return (0);
	return (_venture(tree->left, depth, level + 1) &&
			_venture(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d;

	if (tree)
	{
		d = get_a_depth(tree);
		return (_venture(tree, d, 0));
	}	
	return (0);
}