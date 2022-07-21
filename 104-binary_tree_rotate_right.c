#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (!tree || !tree->left)
		return (NULL);

	if (tree && tree->parent)
	{
		tmp = tree->parent;
	}
	if (tree && tree->left)
	{
		tree->parent = tree->left;
		if (tree->left->right)
		{
			tree->left = tree->parent->right;
			tree->left->parent = tree;
		}
		else
			tree->left = NULL;
		tree->parent->right = tree;

		if (tmp)
		{
			if (tmp->n > tree->parent->n)
				tmp->right = tree->parent;
			else if (tmp->n < tree->parent->n)
				tmp->left = tree->parent;
			tree->parent->parent = tmp;
		}
		else
			tree->parent->parent = NULL;
	}
	tree = tree->parent;
	return (tree);
}
