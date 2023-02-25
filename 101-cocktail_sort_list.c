#include "sort.h"
#include <stdio.h>
/**
 * cocktail_sort_list - sorts a list using he cocktail sort algorithm
 * @list: is the head of the node
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *forward, *backward;
	int flag = 1;

	head = *list;

	while (flag)
	{
		flag = 0;
		forward = head;
		while (forward && forward->next)
		{
			if (forward->n > forward->next->n)
			{
				swapper(list, forward, forward->next);
				print_list(*list);
				flag = 1;
			}
			forward = forward->next;
		}

		backward = forward;

		while (backward && backward->prev)
		{
			if (backward->n < backward->prev->n)
			{
				swapper(list, backward->prev, backward);
				print_list(*list);
				flag = 1;
			}
			backward = backward->prev;
		}
	}
}

/**
 * swapper - swaps two nodes
 * @list: is the head of the list
 * @a: node to be swapped
 * @b: node to be swapped
 *
 * Return: Nothing
 */
void swapper(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->next = a;

	b->prev = a->prev;
	a->prev = b;
}

