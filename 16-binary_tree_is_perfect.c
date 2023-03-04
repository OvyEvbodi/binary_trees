#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1, if tree is perfect,
 * otherwise 0. If tree is NULL, 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t max_depth = 0, level = 0;

	if (!tree)
		return (0);
	max_depth = binary_tree_height(tree);
	return (perfect_tree(tree, max_depth, level));
}

/**
 * perfect_tree - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * @max_depth: the height of a tree
 * @level: the level of the root node
 *
 * Return: 1, if tree is perfect,
 * otherwise 0. If tree is NULL, 0
 */
int perfect_tree(const binary_tree_t *tree, size_t max_depth, size_t level)
{
	if (!tree)
		return (1);
	if (binary_tree_is_leaf(tree))
		return (max_depth == level + 1 ? 0 : 1);
	if (!tree->left || !tree->right)
		return (0);
	return (perfect_tree(tree->left, max_depth, level + 1) &&
		perfect_tree(tree->right, max_depth, level + 1));
}

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
	return (binary_tree_height(tree->left) >=
		binary_tree_height(tree->right) ?
		binary_tree_height(tree->left) + 1 :
		binary_tree_height(tree->right) + 1);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a leaf,
 * otherwise 0, if node is NULL, or not a leaf
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if ((!node) ||  (node && (node->left || node->right)))
		return (0);
	return (1);
}
