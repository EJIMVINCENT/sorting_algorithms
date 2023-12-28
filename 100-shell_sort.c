#include "sort.h"

/**
 * swapInts - Swap two int in an array.
 *
 * @a: The first int to swap.
 * @b: The second int to swap.
 *
 */

void swapInts(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * shell_sort - a function that sorts an array of integers in
 * ascending order using the Shell sort algorithm and the Knuth sequence
 *
 * @array: array of ints to be sorted
 * @size: size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swapInts(array + j, array + (j - gap));
		}
		print_array(array, size);
	}
}
