#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm with sentinel node
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *cur, *temp, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    cur = (*list)->next;

    while (cur != NULL)
    {
        temp = cur->next;
        prev = cur->prev;

        while (prev != NULL && prev->n > cur->n)
        {
            next = prev->prev;

            /* Adjust pointers for swapping */
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

            /* Update prev for the next iteration */
            prev = next;
	    print_list(*list);
        }

        cur = temp;
    }
}
