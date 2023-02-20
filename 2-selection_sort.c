#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: is pointer to the unsorted array
 * @size: is the size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_val, index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_val = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				index = j;
			}
		}
		if (array[i] != min_val)
		{
			array[index] = array[i];
			array[i] = min_val;
			print_array(array, size);
		}

	}
}
