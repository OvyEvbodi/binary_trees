#ifndef QUEUE_H
#define QUEUE_H

#include "binary_trees.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct queue_s
{
        const binary_tree_t *tree;
        struct queue_s *prev;
        struct queue_s *next;
} queue_t;

void _pop(queue_t **queue);
void _push(queue_t **queue, const binary_tree_t *tree);
void _pint(queue_t **queue);
void free_queue(queue_t **queue);

#endif /*QUEUE_H*/
