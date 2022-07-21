#include "binary_trees.h"
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
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

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
				printf("%d\n", new_node->n);
				new_node->right = binary_tree_node(new_node, value);
				/**if (binary_tree_is_avl((*tree)->right) == 0)
				{
					binary_tree_rotate_left(new_node->right);
					binary_tree_rotate_right(new_node);
					return (new_node->parent);
				}*/
				printf("%d\n", new_node->n);
				return (new_node->right);
			}
			new_node = new_node->right;
		}
		else if (new_node->n > value)
		{
			if (!new_node->left)
			{
				new_node->left = binary_tree_node(new_node, value);
				printf("%d\n", new_node->n);
				/**if (binary_tree_is_avl((*tree)->right) == 0)
				{
					binary_tree_rotate_left(new_node->right);
					binary_tree_rotate_right(new_node);
					return (new_node->parent);
				}*/
				printf("%d\n", new_node->n);
				return (new_node->left);
			}
			new_node = new_node->left;
		}
	}
	return (NULL);
}
