#include "sort.h"

/**
 * cocktail_sort_list - sorting using cocktailing
 * @list: pointer to hest of list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		temp = *list;

		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_node(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->next;
		}

		if (!swapped)
			break;
		swapped = 0;
		temp = temp->prev;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_node(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	} while (swapped);
}

/**
 * swap_node - swap a node
 * @list: pointer of head of list
 * @node1: first node
 * @node2: second node
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next2;

	prev1 = node1->prev;
	next2 = node2->next;

	if (prev1 != NULL)
		prev1->next = node2;

	else
		*list = node2;

	if (next2 != NULL)
		next2->prev = node1;

	node1->prev = node2;
	node1->next = next2;

	node2->prev = prev1;
	node2->next = node1;
}
