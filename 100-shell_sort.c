#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 *              algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, m, n;
	int tmp;

	if (array == NULL || size < 2)
		return;
	/* Calculate the initial gap using Knuth sequence */
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (m = gap; m < size; m++)
		{
			tmp = array[m];
			n = m;
			while (n >= gap && array[n - gap] > tmp)
			{
				array[n] = array[n - gap];
				n -= gap;
			}
			array[n] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
