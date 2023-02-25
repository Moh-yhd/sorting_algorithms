#include "sort.h"
#include <stdio.h>
void cocktail_sort_list(int *array, size_t size)
{
	int i, j;
	int tmp;
	int flag = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				printf("forward sorted; ");
				print_array(array, size);
				flag = 1;

			}
		}
		if (flag == 0)
			break;
		for (; j >= 1; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				printf("backward sorted: ");
				print_array(array, size);
			}
		}	
		flag = 0;
	}
}

int main(void)
{
//	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int array[] = {4, 6, 7, 2, 1, 5, 8, 3};
	print_array(array, 8);
	cocktail_sort_list(array, 8);
	print_array(array, 8);

}



