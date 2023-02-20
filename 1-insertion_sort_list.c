#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using the
 * insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of a doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev_node, *current_node, *next_node;

	if (!list || !*list || !(*list)->next)
		return;

	current_node = (*list)->next;
	while (current_node != NULL)
	{
		next_node = current_node->next;

		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			prev_node = current_node->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current_node;

			current_node->prev = prev_node->prev;
			prev_node->next = current_node->next;

			if (current_node->next != NULL)
				current_node->next->prev = prev_node;

			prev_node->prev = current_node;
			current_node->next = prev_node;
			if (current_node->prev == NULL)
				*list = current_node;
			print_list(*list);
		}
		current_node = next_node;
	}
}
