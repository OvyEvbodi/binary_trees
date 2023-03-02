#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @tree: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node,
 * or NULL, if node is NULL, the parent is NULL node has no sibling
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left != node)
			return (node->parent->left);
		else
			return (node->parent->right);
	}
	FAIL;
}
