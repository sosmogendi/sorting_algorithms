#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *l, *r;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		l = *list;
		while (l->next != NULL)
		{
			if (l->n > l->next->n)
			{
				r = l->next;
				if (l->prev != NULL)
					l->prev->next = r;
				else
					*list = r;
				if (r->next != NULL)
					r->next->prev = l;
				l->next = r->next;
				r->prev = l->prev;
				r->next = l;
				l->prev = r;
				l = r;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				l = l->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		r = l;
		while (r->prev != NULL)
		{
			if (r->n < r->prev->n)
			{
				l = r->prev;
				if (r->next != NULL)
					r->next->prev = l;
				else
					*list = l;
				if (l->prev != NULL)
					l->prev->next = r;
				r->prev = l->prev;
				l->next = r->next;
				l->prev = r;
				r->next = l;
				r = l;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				r = r->prev;
			}
		}
	} while (swapped);
}
