#include "sort.h"

/**
 * split_array - function that splits an array to subarray
 * @array: pointer to the array
 * @temp: temporary array for merging
 * @start: the lower bound
 * @end: the upper bound
 * Return: Void
 */
void split_array(int *array, int *temp,  size_t start, size_t end)
{
	size_t mid, i, j;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		/* divide array into halves*/
		split_array(array, temp, start, mid);
		split_array(array, temp, mid + 1, end);
		printf("Merging...\n");
		printf("[left]: ");

		for (i = start; i <= mid; i++)
		{
			printf("%d", array[i]);
			if (i < mid)
			{
				printf(", ");
			}
		}
		printf("\n");
		printf("[right]: ");
		for (j = mid + 1; j <= end; j++)
		{
			printf("%d", array[j]);
			if (j < end)
			{
				printf(", ");
			}
		}
		printf("\n");
		sub_array_merge(array, temp, start, mid, mid + 1, end);
	}
}

/**
 * sub_array_merge - function thats divides an array to sub array
 * @array: Pointer to the array
 * @temp: beffer to store sorted subarray
 * @ls: left start
 * @le: left end
 * @rs: right start
 * @re: right end
 * Return: void
 */
void sub_array_merge(int *array, int *temp, size_t ls, size_t le, size_t rs, size_t re)
{
	size_t i, j, k, left_size, right_size;

	left_size = le - ls + 1;
	right_size = re - rs + 1;

	i = ls; j = rs; k = 0;

	while (i <= le && j <= re)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}
	if (i > le)
	{
		while (j <= re)
		{
			temp[k++] = array[j++];
		}
	}
	else
	{
		while ( i <= le)
		{
			temp[k++] = array[i++];
		}
	}
	for (i = 0; i < left_size; i++)
	{
		array[ls + i] = temp[i];
	}
	for (j = 0; j < right_size; j++)
	{
		array[rs + j] = temp[left_size + j];
	}
	printf("[Done]: ");

	for (i = ls; i <= re; i++)
	{
		printf("%d", array[i]);

		if (i < re)
			printf(", ");
	}
	printf("\n");

}
/**
 * merge_sort -merges an array into ascending order using merge sort
 * @array: pointer to the array to sort
 * @size: the size of an array
 *
 * Return: Void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	split_array(array, temp, 0, size - 1);
	free(temp);
}
