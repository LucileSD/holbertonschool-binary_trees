#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts a node as the right-child
 * of another node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	new_node->right = parent->right;

	parent->right = new_node;

	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}
