#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;


	if (!(*tree) || !tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = *tree;

	while (new_node)
	{
		if (new_node->n == value)
			return (NULL);

		if (new_node->n < value)
		{
			if (!new_node->right)
			{
				new_node->right = binary_tree_node(new_node, value);
				return (new_node->right);
			}
			new_node = new_node->right;
		}
		if (new_node->n > value)
		{
			if (!new_node->left)
			{
				new_node->left = binary_tree_node(new_node, value);
				return (new_node->left);
			}
			new_node = new_node->left;
		}
	}
	return (NULL);
}
