#include "sort.h"

/**
 * insertion_sort_list - Sort doubly linked list of ints in ascending order
 *
 * @list: Pointer to doubly linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *prev, *next;
	/*int tmp;*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	if
	while (cur != NULL)
	{
		next = cur->next;
		prev = cur->prev;

		while (prev != NULL && prev->n > cur->n)
		{
			prev->next = cur->next;

			if (cur->next != NULL)
				cur->next->prev = prev;

			cur->prev = prev->prev;
			cur->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = cur;
			else
				*list = cur;

			prev->prev = cur;

			prev = cur->prev;
			print_list(*list);

		}
		cur = next;

	}
}
