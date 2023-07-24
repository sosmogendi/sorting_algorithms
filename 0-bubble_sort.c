#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		swapped = 0;
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				/* Swap elements */
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		/* The array is already sorted */
		if (swapped == 0)
			break;
	}
}
