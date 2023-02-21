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
	quick_sorter(array, 0, size - 1, size);

}

/**
 * quick_sorter - sorts an array using the quick sort algorithm
 * @array: is a pointer to the array to be sorted
 * @low: is the start of the array
 * @high: is the end of the array
 * 
 * Return: Nothing
 */
void quick_sorter(int *array, int low, int high, size_t size)
{
	int pi;

	
	if (low < high)
	{
		pi = lumuto_partition(array, low, high, size);
		quick_sorter(array, low , pi - 1, size);
		quick_sorter(array, pi + 1, high, size);
		print_array(array, size);
	}
}

/**
 * lumuto_partition - partitions an array as per the lumuto algorithm
 * @array: is a pointer to the array to be partitioned
 * @low: is the start of the array
 * @high: is the end of the array
 *
 * Return: Nothing
 */
int lumuto_partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot, tmp;

	pivot = array[high];
	if (0)
		printf("%ld", size);
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot) /* swap i and j */
		{
		/*	printf("array[j] = %d\npivot = %d\n", array[j], pivot);
		 *	*/
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	array[high] = array[i + 1];
	array[i + 1] = pivot;
	return (i + 1);
}
