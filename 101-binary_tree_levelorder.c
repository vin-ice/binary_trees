#include "binary_trees.h"

/**
 * enqueue - adds element to end of array
 * @arr: array to add ele
 * @ele: element to insert
 * @i: index to insert
*/
void enqueue(binary_tree_t **arr, binary_tree_t *ele, int i)
{
    if (*arr == NULL || ele == NULL)
        return;
    arr[i] = ele;
}
/**
 * dequeue - removes first element and shifts
 *  the rest
 * @arr: array to remove first ele
*/
binary_tree_t *dequeue(binary_tree_t **arr)
{
    int i;
    binary_tree_t *node = NULL;
    
    if (arr[0])
    {
        node = arr[0];
        for (i = 0; i < 3; i++)
            arr[i] = arr[i + 1];
        arr[i] = NULL;
    }
    return (node);
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
    binary_tree_t *queue[4], *front = NULL;
    int rear = 0;

    if (!tree || !func)
        return;
    
    enqueue(queue, (binary_tree_t *) tree, rear++);
    while ((front = dequeue(queue)))
    {
        rear--;
        if (front->left)
            enqueue(queue, front->left, rear++);
        if (front->right)
            enqueue(queue, front->right, rear++);
        func(front->n);
    }

}