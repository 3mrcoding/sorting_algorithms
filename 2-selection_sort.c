#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		/* Declair smallest number in array */
		for (j = i; j < size; j++)
		{
			if (array[min_idx] > array[j])
			{
				if (min_idx == 0 || array[min_idx] > array[j])
					min_idx = j;
			}
		}
		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;
		print_array(array, size);
	}
}
