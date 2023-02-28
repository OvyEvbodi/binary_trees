#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree,
 * or 0, if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (1 + binary_tree_height(tree->left));
}
