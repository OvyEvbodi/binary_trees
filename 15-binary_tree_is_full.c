#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1, if tree is full,
 * otherwise, 0, if not full, or tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	return (full_tree(tree));
}

/**
 * full_tree - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1, if tree is full,
 * otherwise, 0, if not full, or tree is NULL
 */

int full_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if ((!tree->left && !tree->right))
		return (1);
	if (tree->left && tree->right)
		return (full_tree(tree->left) && full_tree(tree->right));
	return (0);
}
