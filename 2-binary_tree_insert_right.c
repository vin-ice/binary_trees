#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the 
 * right child of another node
 * @parent: Pointer to the parent of the binary tree
 * @value: Value to store in the node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL, *temp = NULL;

    if (parent)
    {
        temp = parent->right;
        node = malloc(sizeof(binary_tree_t));
        if (node)
        {
            node->n = value;
            node->left = NULL;
            node->parent = parent;
            parent->right = node;
            node->right = temp;
            if (temp)
                temp->parent = node;
        }    
    }
    return (node);
}