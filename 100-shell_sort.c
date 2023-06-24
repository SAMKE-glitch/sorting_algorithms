#include "sort.h"

/**
 * shell_sort - function thatsorts array in asceinding using shellsort
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int value;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < (size / 3))
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j >= gap && array[j - gap] > value)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = value;
		}
		print_array(array, size);
		gap /= 3;
	}
}
