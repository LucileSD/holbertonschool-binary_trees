#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: sum
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t sum = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		sum++;
	else
		sum = binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left);

	return (sum);
}
