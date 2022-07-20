#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include "110-binary_tree_is_bst.c"
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  a pointer to the root node of the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst = binary_tree_is_bst(tree);
	int bf = binary_tree_balance(tree);

	if (!tree)
		return (0);

	if (bst == 1 && (bf == 1 || bf == 0 || bf == -1))
	{
		if (!tree->right && !tree->left)
			return (1);

		else if (tree->left && !tree->right)
			return (binary_tree_is_avl(tree->left));

		else if (tree->right && !tree->left)
			return (binary_tree_is_avl(tree->right));

		else
		{
			return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
		}
	}
	return (0);
}
