#include "sort.h"


/**
 * swapNodes - swap two nodes in a listint_t doubly-linked list.
 *
 * @h: A pointer to the head of the doubly-linked list.
 * @previous: A pointer to the first node to swap.
 * @current: The second node to swap.
 *
 */


void swapNodes(listint_t **h, listint_t **previous, listint_t *current)
{
	(*previous)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *previous;
	current->prev = (*previous)->prev;
	current->next = *previous;
	if ((*previous)->prev != NULL)
		(*previous)->prev->next = current;
	else
		*h = current;
	(*previous)->prev = current;
	*previous = current->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of.
 *
 * integers in Ascending order.
 * @list: A pointer to the head of the doubly linked list.
 *
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		previous = current->prev;
		while (previous != NULL && current->n < previous->n)
		{
			swapNodes(list, &previous, current);
			print_list((const listint_t *)*list);
		}
	}
}
