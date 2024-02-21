#include "sort.h"

/**
 * insertion_sort_list - sorting items using insertion
 * @list: Input list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		while (current_node->prev != NULL && current_node->n < current_node->prev->n)
		{
			prev_node = current_node->prev;

			prev_node->next = current_node->next;
			if (current_node->next != NULL)
				current_node->next->prev = prev_node;

			current_node->prev = prev_node->prev;
			current_node->next = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = current_node;
			else
				*list = current_node;

			prev_node->prev = current_node;
			print_list(*list);
		}

		current_node = next_node;
	}
}
