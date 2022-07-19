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

	tree->parent = tree->left;
	tmp = tree->left->right;

	if (tmp)
	{
		tree->left = tree->parent->right;
		tmp->parent = tree;
	}
	else
		tree->left = NULL;
	tree->parent->right = tree;
	tree = tree->parent;

	return (tree);
}
