#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm with sentinel node
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *cur, *temp, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    cur = (*list)->next;

    while (cur != NULL)
    {
        temp = cur;
        prev = cur->prev;

        while (prev != NULL && prev->n > cur->n)
        {
            prev->next = temp->next;

            /* Adjust pointers for swapping */
            /*prev->next = cur->next;*/
            if (temp->next != NULL)
                temp->next->prev = prev;

            temp->prev = prev->prev;
            temp->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;
	    prev = temp->prev;

            /* Update prev for the next iteration */
            /*prev = next;*/
	    print_list(*list);
        }

        cur = cur->next;
    }
}
