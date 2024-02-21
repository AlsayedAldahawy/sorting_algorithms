#include "sort.h"

/**
 * counting_sort - sorting elements using counting sort
 * @array: input array
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int max, i, ii, iii, *count, *result;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	result = malloc(sizeof(int) * size);

	if (count == NULL || result == NULL)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (ii = 0; ii < (int) size; ii++)
		count[array[ii]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (ii = size - 1; ii >= 0; ii--)
	{
		result[count[array[ii]] - 1] = array[ii];
		count[array[ii]]--;
	}

	for (iii = 0; iii < (int)size; iii++)
		array[iii] = result[iii];

	free(count);
	free(result);
}
