#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    size_t max_val = 0;
    size_t i;
    int *count_arr;
    int *tmp_arr;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if ((size_t)array[i] > max_val)
            max_val = array[i];
    }

    count_arr = malloc(sizeof(int) * (max_val + 1));
    if (count_arr == NULL)
        return;

    for (i = 0; i <= max_val; i++)
        count_arr[i] = 0;

    for (i = 0; i < size; i++)
        count_arr[array[i]]++;

    for (i = 1; i <= max_val; i++)
        count_arr[i] += count_arr[i - 1];

    tmp_arr = malloc(sizeof(int) * size);
    if (tmp_arr == NULL)
    {
        free(count_arr);
        return;
    }

    for (i = size - 1; i < (size_t)-1; i--)
    {
        tmp_arr[count_arr[array[i]] - 1] = array[i];
        count_arr[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = tmp_arr[i];

    free(count_arr);
    free(tmp_arr);
}
