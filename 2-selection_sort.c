#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *					order using the Selection sort algorithm
 *
 * @array: The array of ints to be sorted
 * @size: Size of the array.
 *
 */


void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, swapIndex;
	int temp;

	if (size < 2)
		return;
	if (size == 2 && array[0] < array[1])
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[swapIndex])
			{
				swapIndex = j;
			}
		}
		if (swapIndex != i)
		{
			temp = array[swapIndex];
			array[swapIndex] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}

}
