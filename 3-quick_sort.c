#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 *
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 *
 * Return: Index of the pivot element
 *
 */

int lomuto_partition(int *array, int size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Quick sort recursive function
 *
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 *
 */

void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, partition_index - 1);
		quick_sort_recursive(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
