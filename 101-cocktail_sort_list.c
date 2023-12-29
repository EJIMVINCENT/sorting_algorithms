#include "sort.h"


/**
 * swapNodeAhead - Swaps two nodes of a linked list in forward order
 *
 * @list: Head of the list
 * @tail: Last unsorted element
 * @curr: current element.
 *
 */

void swapNodeAhead(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *tmp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*curr)->prev;
	(*curr)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = tmp;
	tmp->next = *curr;
	*curr = tmp;
}


/**
 * swapNodeBehind - Swaps two nodes of a linked list in backwards order
 *
 * @list: Head of the list
 * @tail: Last unsorted element
 * @curr: current element.
 *
 */

void swapNodeBehind(listint_t **list, listint_t **tail, listint_t **curr)
{
	listint_t *tmp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*curr)->next;
	(*curr)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = tmp;
	tmp->prev = *curr;
	*curr = tmp;
}


/**
 * cocktail_sort_list - Sort a list using cocktail sort.
 *
 * @list: Head of the list to be sorted.
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *curr;
	bool swap = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swap == true)
	{
		swap = false;
		for (curr = *list; curr != tail; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swapNodeAhead(list, &tail, &curr);
				print_list((const listint_t *)*list);
				swap = true;
			}
		}
		for (curr = curr->prev; curr != *list;
				curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swapNodeBehind(list, &tail, &curr);
				print_list((const listint_t *)*list);

				swap = true;
			}
		}
	}
}
