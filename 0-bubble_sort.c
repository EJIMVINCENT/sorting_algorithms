#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints using bubble sort algorithm.
 *
 * @array: Array to be sorted
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t len = size, j;
	int temp;
	short swap = 1;

	if (size < 2)
		return;
	while (swap == 1)
	{
		swap = 0;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		len--;
	}

}
