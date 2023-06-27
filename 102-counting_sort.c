#include "sort.h"

/**
 * counting_sort - sort an array of intergers in ascending order using
 * the counting sort alogarithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array = NULL, *sort_array = NULL;
	int i, max;

	if (array == NULL || size < 2)
		return;
	max = 0;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	memset(count_array, 0, (max + 1) * sizeof(int));
	/*count array*/
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	/*feed array to actual poz*/
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);
	/*allocate sort mem*/
	sort_array = malloc(size * sizeof(int));
	if (sort_array == NULL)
	{
		free(count_array);
		return;
	}
	/*sort array*/
	for (i = 0; i < (int)size; i++)
	{
		sort_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	/*copy sort array to og array*/
	memcpy(array, sort_array, size * sizeof(int));

	free(count_array);
	free(sort_array);
}
