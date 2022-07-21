#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
        return(binary_tree_node(*tree, value));
 
    if (value < (*tree)->n)
        (*tree)->left  = bst_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        (*tree)->right = bst_insert(&(*tree)->right, value);
    else
        return (*tree);

    int balance = binary_tree_balance(*tree);
 
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);
 
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);
 
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left =  binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }
 
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }
    return (*tree);
}
