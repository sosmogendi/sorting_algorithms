#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm with Lomuto partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int m = low - 1, n;

	for (n = low; n <= high - 1; n++)
	{
		if (array[n] <= pivot)
		{
			m++;
			if (m != n)
			{
				swap(&array[m], &array[n]);
				print_array(array, size);
			}
		}
	}
	if (m + 1 != high)
	{
		swap(&array[m + 1], &array[high]);
		print_array(array, size);
	}
	return (m + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
