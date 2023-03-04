#include "binary_trees.h"

/**
 * _iscomplete - compares indexes of nodes to see if they
 * are in order
 * @tree: tree
 * @idx: expected index of node
 * @size: size of tree
*/
int _iscomplete(const binary_tree_t *tree, size_t idx, size_t size)
{
	if (tree)
	{
		if (idx >= size)
			return (0);
		return (_iscomplete(tree->left, 2 * idx + 1, size) &&
				_iscomplete(tree->right, 2 * idx + 2, size));
	}
	return (1);
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree)
	{
		size = binary_tree_size(tree);
		return (_iscomplete(tree, 0, size));
	}
    return (0);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
