#include "sort.h"

/**
 * swap - swap two values
 * @a: pointer of first value
 * @b: pointer to second value
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lamuto partition scheme
 * @array: pointer to the array
 * @low: start index of the partion
 * @high: ending of the partion
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;
	
	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			/*i++;*/
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - recursive function to sort an array using quick sort algorithm
 * @array: pointer to array
 * @low: starting index of partition
 * @high: ending index of the partition
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = lomuto_partition(array, low, high, size);

		quicksort(array, low, i - 1, size);
		quicksort(array, i + 1, high, size);
	}
}

/**
 * quick_sort - sort an array of intergers in ascending order using quick sort algorith
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
