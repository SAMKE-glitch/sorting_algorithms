#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending order
 * @array: pointer to the array to be sorted
 * @size: The size of the elements array to be sorted
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
