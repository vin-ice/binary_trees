#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary node
 * @parent: Pointer to the payment node
 * @value: Value to put in the new node
 * Return: Pointer to new node or NULL
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL, *head = NULL, *prev = NULL;

    node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        perror("node"); 
    else
    {
        node->n = value;
        node->left = NULL;
        node->right = NULL;

        if (parent == NULL)
        {
            node->parent = NULL;
            parent = node;
        }     
        else
        {
            for (head = parent; head;)
            {
                prev = head;

                if (head->n < node->n)
                    head = head->right;
                else
                    head = head->left;
            }
            node->parent = prev;
            
            if (prev->n < node->n)
                parent->right = node;
            else
                parent->left = node;
        }
    }
    return (node);
}