#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the nodes with at least
 * 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: number of parent
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t s = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		s = binary_tree_nodes(tree->right) + 1 + binary_tree_nodes(tree->left);
	else
		return (0);

	return (s);
}
