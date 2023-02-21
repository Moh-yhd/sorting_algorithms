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


}

size_t lumuto_partition(int *array, size_t low, size_t higb)
{
	size_t i, j;
	int pivot, tmp;

	pivot = array[high - 1];
	i = low;
	for (j = i; j < size - 1; j++)
	{
		if (array[j] <= pivot) /* swap i and j */
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i++;
		}
	}
	array[high - 1] = array[i];
	array[i] = pivot;
	return (i);
}
