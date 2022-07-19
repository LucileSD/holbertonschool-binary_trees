#include "binary_trees.h"

/**
 * is_bst - function that checks if a binary tree is a valid Binary
 * Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value a node on the left side
 * @max: the maximum value of node on the right side
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
	is_bst(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid Binary
 * Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
