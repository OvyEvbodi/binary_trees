#include "binary_trees.h"

int sum = 0;

/**
 * leaves_count - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: void
 */

void leaves_count(const binary_tree_t *node)
{
	if (node && (!node->left && !node->right))
		sum++;
}

/**
 * tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */
void tree_preorder(const binary_tree_t *tree, void (*func)(const binary_tree_t *))
{
	if (tree)
	{
		func(tree);
		tree_preorder(tree->left, func);
		tree_preorder(tree->right, func);
	}
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: the number of leaves in the tree,
 * or 0, if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int res = 0;
	if (tree)
		tree_preorder(tree, &leaves_count);
	res = sum;
	sum = 0;
	return (res);
}
