#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array following the shell algorithm
 * @array: is the pointer to the array to be sorted
 * @size: is the size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int tmp;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;
	for (gap /= 3; gap > 0;  gap = gap / 3)
	{
		for (i = 0; i < size; i++)
		{
			j = i;
			for (; j >= gap && j < size; j--)
			{
				if (array[j] < array[j - gap])
				{
					tmp = array[j];
					array[j] = array[j - gap];
					array[j - gap] = tmp;
				}
			}
		}
		print_array(array, size);
	}

}
