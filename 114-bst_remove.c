#include "binary_trees.h"
/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing
 * the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *next_root, *mother;

	if (!root)
		return (root);
	if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
	{
		if (!root->left && !root->right)
		{	free(root);
			root = NULL; }
		else if (root->left && root->right)
		{
			next_root = root->right;
			while (next_root->left)
				next_root = next_root->left;
			root->n = next_root->n;
			root->right = bst_remove(root->right, next_root->n);
		}
		else if (!root->right && root->left)
		{
			tmp = root;
			mother = root->parent;
			root = root->left;
			root->parent = mother;
			free(tmp);
		}
		else if (!root->left && root->right)
		{
			tmp = root;
			mother = root->parent;
			root = root->right;
			root->parent = mother;
			free(tmp);
		}
	}
	return (root);
}
