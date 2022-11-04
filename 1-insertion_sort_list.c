#include "sort.h"
#include <stdio.h>


void swap(listint_t *swap)
{
	listint_t *previous, *nxt;

	previous = swap->prev;
	nxt = swap->next;

	while (previous->prev != NULL && (previous->prev-> n > swap->n))
		previous = previous->prev;

	swap->prev->next = nxt;
	if (nxt != NULL)
		nxt->prev = swap->prev;

	if(previous->prev == NULL)
		swap->prev = NULL;
	else
	{
		swap->prev = previous->prev;
		swap->prev->next = swap;
	}
	swap->next = previous;
	previous->prev = swap;
}

/**
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *nxt, *previous;

	// handle cases where len <= 2
	while (current != NULL)
	{
		previous = current->prev;
		nxt = current->next;
		if (previous == NULL)
		{
			current = nxt;
			continue;
		 }

		if (previous->n > current->n)
			swap(current);

		current = nxt;
		continue;
	}

}
