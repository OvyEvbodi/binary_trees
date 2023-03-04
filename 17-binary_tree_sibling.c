#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node,
 * or NULL, if node is NULL, the parent is NULL, or node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left && node->parent->left != node)
			return (node->parent->left);
		if (node->parent->right && node->parent->right != node)
			return (node->parent->right);
	}
	FAIL;
}
