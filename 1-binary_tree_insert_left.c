#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the 
 * left child of another node
 * @parent: Pointer to the parent of the binary tree
 * @value: Value to store in the node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL, *temp = NULL;

    if (parent)
    {
        temp = parent->left;
        node = malloc(sizeof(binary_tree_t));
        if (node)
        {
            node->n = value;
            node->right = NULL;
            node->parent = parent;
            parent->left = node;
            node->left = temp;
            if (temp)
                temp->parent = node;
        }    
    }
    return (node);
}