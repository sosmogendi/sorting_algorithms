#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	sorted = (*list)->next;
	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;
		prev = current->prev;
		next = current->next;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (next != NULL)
				next->prev = prev;
			current->prev = prev->prev;
			prev->next = next;
			prev->prev = current;
			current->next = prev;
			prev = current->prev;
			next = current->next;
			if (prev == NULL)
				*list = current;
			print_list(*list);
		}
	}
}
