#include "sort.h"

/**
 * bitonic_sort - set elements to bitonic
 * @array: input array
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	int sorted = 1;

	if (!array || size < 2)
		return;

	bitonic(array, 0, size, sorted, size);
}

/**
 * bitonic - implementation of bitonic
 * @array: input array
 * @low: first element
 * @elements: no of elements
 * @sorted: 0 for descending and 1 for ascending
 * @size: size of array
 */
void bitonic(int array[], int low, int elements, int sorted, int size)
{
	int middle;

	if (elements > 1)
	{
		if (sorted >= 1)
		{
			printf("Merging [%d/%d] (UP):\n", elements, size);
			print_array(&array[low], elements);
		}

		else
		{
			printf("Mergin [%d/%d] (DOWN):\n", elements, size);
			print_array(&array[low], elements);
		}

		middle = elements / 2;
		bitonic(array, low, middle, 1, size);
		bitonic(array, low + middle, middle, 0, size);
		merge_bitonic(array, low, elements, sorted);

		if (sorted <= 0)
		{
			printf("Result [%d/%d] (DOWN):\n", elements, size);
			print_array(&array[low], elements);
		}

		if (sorted >=  1)
		{
			printf("Result [%d/%d] (UP):\n", elements, size);
			print_array(&array[low], elements);
		}
	}
}

/**
 * merge_bitonic - sort in both orders
 * @array: input array
 * @low: first element
 * @elements: no of elements
 * @sorted: 0 for descending and 1 for ascending
 */
void merge_bitonic(int array[], int low, int elements, int sorted)
{
	int middle, i;

	if (elements > 1)
	{
		middle = elements / 2;
		for (i = low; i < low + middle; i++)
		{
			swap_bitonic(array, i, i + middle, sorted);
		}
		merge_bitonic(array, low, middle, sorted);
		merge_bitonic(array, low + middle, middle, sorted);
	}
}

/**
 * swap_bitonic - swap elements
 * @array: input array
 * @element1: first element
 * @element2: second element
 * @sorted: 0 for descending and 1 for ascending
 */
void swap_bitonic(int array[], int element1, int element2, int sorted)
{
	int tmp;

	if (sorted == (array[element1] > array[element2]))
	{
		tmp = array[element1];
		array[element1] = array[element2];
		array[element2] = tmp;
	}
}
