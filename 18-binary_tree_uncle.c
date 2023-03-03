#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node,
 * or NULL, if node is NULL, the parent is NULL, or node has no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left && node->parent->parent->left != node->parent)
			return (node->parent->parent->left);
		if (node->parent->parent->right)
			return (node->parent->parent->right);
	}
	FAIL;
}
