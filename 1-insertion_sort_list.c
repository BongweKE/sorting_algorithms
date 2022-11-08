#include "sort.h"

/**
 * check_if_list_sortable - a function to check out a doubly linked list
 * before it's sorted to know if there's a need to sort it
 * @list: pointer to the address of the head node of a list
 *
 * Return: 1 if sortable, 0 if not
 */
int check_if_list_sortable(listint_t **list)
{
	listint_t *current;
	int size = 0;

	/* edge case for NULL list */
	if (list == NULL)
		return (0);

	current = *list;
	/* handle cases where len < 2 */
	while (current != NULL)
	{
		size++;
		current = current->next;
	}

	if (size < 2)
		return (0);

	return (1);
}

/**
 * reset_head - a function to change the pointer to a list's
 * head node after swapping, just in case a swap was made to
 * the head node
 *
 * @list: the pointer to the address of the head node of a
 * doubly linked list
 */
void reset_head(listint_t **list)
{
	/* change location of head */
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}

/**
 * swap - a function to move a node we have detected is on the
 * wrong location in the list and move it to it's most correct
 * location
 * @swap: the location of the node whoch we want to move
 *
 * Description: We loop backwards looking through the previous
 * nodes to see if they hold a value that's greater than the
 * value of the node to be swapped
 * this is repeated until we find a node previous which is supposed
 * to either be the head or before a node which holds a value which
 * is smaller than our node to be swapped
 * At this point, insertion into this location in the doubly linked
 * list is done
 */
void swap(listint_t *swap)
{
	listint_t *previous, *nxt;

	previous = swap->prev;
	nxt = swap->next;

	while (previous->prev != NULL && (previous->prev->n > swap->n))
		previous = previous->prev;

	swap->prev->next = nxt;
	if (nxt != NULL)
		nxt->prev = swap->prev;

	if (previous->prev == NULL)
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
 * recursive_insertion - a function to sort a doubly linked list
 * using insertion sort.
 * @list: a pointer to the location of the address of the head of the
 * doubly linked list
 *
 * Description: This function first checks if the length of the list is
 * less than two and doesn't try to sort such lists
 * However, for longer lists, It checks to see if the node before the
 * current node i
 * To ensure that this is done repeatedly until we have a run that doesn't
 * swap any node, there's a value called sorted_sth which keeps track
 * of whether a node was swapped out during the while loop and calls this
 * function recursively until it reaches a point where none of the nodes
 * were swapped out
 */
void recursive_insertion(listint_t **list)
{
	listint_t *current, *nxt, *previous;
	int sorted_sth = 0;


	current = *list;

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
		{
			swap(current);
			sorted_sth = 1;
			reset_head(list);
			print_list(*list);
		}
		current = nxt;
	}

	if (sorted_sth == 1)
		insertion_sort_list(list);

}

/**
 * insertion_sort_list - a function to check if a list is sortable
 * and call the recursive sorter to reduce time complexity since
 * if this was in the recursive list a loop would be unnecessarily done each
 * time
 * @list: the pointer to the address of the head node of our doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (check_if_list_sortable(list) == 0)
		return;

	recursive_insertion(list);
}
