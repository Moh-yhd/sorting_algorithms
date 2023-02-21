#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: is a pointer to the array to be sorted
 * @size: is the size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quick_sorter(array, 0, size - 1, size);

}

/**
 * quick_sorter - sorts an array using the quick sort algorithm
 * @array: is a pointer to the array to be sorted
 * @low: is the start of the array
 * @high: is the end of the array
 * @size: is the size of the array
 *
 * Return: Nothing
 */
void quick_sorter(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lumuto_partition(array, low, high, size);
		quick_sorter(array, low, pi - 1, size);
		quick_sorter(array, pi + 1, high, size);
	}
}

/**
 * lumuto_partition - partitions an array as per the lumuto algorithm
 * @array: is a pointer to the array to be partitioned
 * @low: is the start of the array
 * @high: is the end of the array
 * @size: is the size of the array
 *
 * Return: Nothing
 */
int lumuto_partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot;

	pivot = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot) /* swap i and j */
		{
			swap(array, &array[j], &array[i++], size);
		}
	}

	swap(array, &array[i], &array[high], size);
	return (i);
}

/**
 * swap - swaps two elements prints the array
 * @array: pointer to the array to be printed
 * @a: element to be swapped
 * @b: element to be swapped
 * @size: size of the array
 */
void swap(int *array, int *a, int *b, size_t size)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a	- *b;
		print_array(array, size);
	}
}
