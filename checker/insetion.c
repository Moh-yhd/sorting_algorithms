#include "sort.h"
void insertion(int *array, int size)
{
	int i, j, tmp;

	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int array[] = {3, 8, 4, 1, 6, 7, 5, 2};
	print_array(array, 8);
	insertion(array, 8);
	print_array(array, 8);
}


