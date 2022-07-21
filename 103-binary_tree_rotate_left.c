#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree:  a pointer to the root node of the tree
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (!tree || !tree->right)
		return (NULL);

	if (tree && tree->parent)
	{
		tmp = tree->parent;
	}
	if (tree && tree->right)
	{
		tree->parent = tree->right;
		if (tree->right->left)
		{
			tree->right = tree->parent->left;
			tree->right->parent = tree;
		}
		else
			tree->right = NULL;
		tree->parent->left = tree;

		if (tmp)
		{
			if (tmp->n > tree->parent->n)
				tmp->left = tree->parent;
			else if (tmp->n < tree->parent->n)
				tmp->right = tree->parent;
			tree->parent->parent = tmp;
		}
		else
			tree->parent->parent = NULL;
	}
	tree = tree->parent;
	return (tree);
}
