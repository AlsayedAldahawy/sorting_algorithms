#include "sort.h"

/**
 * quick_sort - sorting array using quick sort
 * @array: input array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL ||  size < 2)
		return;

	quick_sort_recu(array, 0, size - 1, size);
}

/**
 * quick_sort_recu - recursive fun for quick sort
 * @array: input array
 * @low: index of low partition
 * @high: index of high partition
 * @size: size of array
 */
void quick_sort_recu(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lpartition(array, low, high, size);
		quick_sort_recu(array, low, partition - 1, size);
		quick_sort_recu(array, partition + 1, high, size);
	}
}

/**
 * lpartition - Lomuto parition scheme for quick sort
 * @array: input array
 * @low: index of low partition
 * @high: index of high partition
 * @size: size of array
 * Return: index of pivot element
 */
int lpartition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
