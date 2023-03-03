#include "queue.h"
#include "binary_trees.h"

/**
 * _push - pushes a new node on to the queue
 * @queue: a pointer to the top of the queue
 * @data: the data to be pushed on to the queue
 *
 * Return: void
 */
void _push(queue_t **queue, const binary_tree_t *tree)
{
	queue_t *new = NULL, *temp = NULL;

	if (!*queue)
	{
		*queue = malloc(sizeof(queue_t));
		if (!*queue)
			free_queue(queue);
		(*queue)->prev = NULL;
		(*queue)->tree = tree;
		(*queue)->next = NULL;
	}
	else
	{
		new = malloc(sizeof(queue_t));
		if (!new)
			free_queue(queue);
        	new->tree = tree;
		temp = *queue;
		while (temp->next)
			temp = temp->next;
		new->next = NULL;
		new->prev = temp;
		temp->next = new;
	}
}

/**
 * _pop - pops a node from the top of the queue
 * @queue:a pointer to the top of the queue
 *
 * Return: void
 */

void _pop(queue_t **queue)
{
	queue_t *temp = NULL;

	if (!*queue)
		free_queue(queue);
	else
	{
		temp = *queue;
		if ((*queue)->next)
			(*queue)->next->prev = NULL;
		*queue = (*queue)->next;
		free(temp);
	}
}

/**
 * _pint - prints the top element of a queue
 * @queue:a pointer to the top of the queue
 *
 * Return: void
*/

void _pint(queue_t **queue)
{
	if (!*queue)
		free_queue(queue);
	printf("num  %d\n", (*queue)->tree->n);
}

/**
 * free_queue - frees a queue list
 *
 * @queue: a pointer to the head node
 *
 * Return: void
*/

void free_queue(queue_t **queue)
{
	queue_t *temp = *queue;

	if (*queue)
	{
		while (temp->next)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(temp);
		temp = NULL;
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree)
	{
		_push(&queue, tree);

		while (queue)
		{
			func(queue->tree->n);
			if (queue->tree->left)
				_push(&queue, queue->tree->left);
			if (queue->tree->right)
				_push(&queue, queue->tree->right);
			_pop(&queue);
		}
	}
}
