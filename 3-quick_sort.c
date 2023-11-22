#include "sort.h"

/**
 * swap - Creates a doubly linked list from an array of integers
 *
 * @i: Array to convert to a doubly linked list
 * @j: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * partition - Creates a doubly linked list from an array of integers
 *
 * @arr: Array to convert to a doubly linked list
 * @l: Size of the array
 * @r: Size of the array
 * @size: Size of the array
 * Return: Pointer to the first element of the created list. NULL on failure
 */
int partition(int *arr, int l, int r, int size)
{
	int pivot = arr[r];
	int i = l;
	int j;

	for (j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			/*print_array(arr, size);*/
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	print_array(arr, size);
	return (i);
}

/**
 * quicksort - Creates a doubly linked list from an array of integers
 *
 * @arr: Array to convert to a doubly linked list
 * @l: Size of the array
 * @r: Size of the array
 * @size: Size of the array
 * Return: Pointer to the first element of the created list. NULL on failure
 */
void quicksort(int *arr, int l, int r, int size)
{
	int i;

	if (l >= r)
		return;

	i = partition(arr, l, r, size);

	if (i != l)
		quicksort(arr, l, i - 1, size);
	quicksort(arr, i + 1, r, size);
}


/**
 * quick_sort - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
void quick_sort(int *array, size_t size)
{
	int l = 0;
	int r = size - 1;

	quicksort(array, l, r, size);

}
