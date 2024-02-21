#include "sort.h"

/**
 * radix_sort - sorting using radix.
 * @array: input array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;

	for (i = 1; sort == 1; i++)
	{
		sort = count_sort(array, size, i);
		print_array(array, size);
	}
}

/**
 * count_sort - sorting using counting sort
 * @array: input array
 * @size: size of array
 * @number: number to sort by
 * Return: (1) to keep sorting otherwise 0.
 */
unsigned int count_sort(int *array, size_t size, unsigned int number)
{
	int i, count[10] = {0};
	int *copy = NULL;
	size_t ii, temp, result = 0;
	unsigned int npw1, npw2, sort = 0;

	npw2 = pow_10(number - 1);
	npw1 = npw2 * 10;
	copy = malloc(sizeof(int) * size);

	if (copy == NULL)
		exit(1);

	for (ii = 0; ii < size; ii++)
	{
		copy[ii] = array[ii];
		if (array[ii] / npw1 != 0)
			sort = 1;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (ii = 0; ii < size; ii++)
		count[(array[ii] % npw1) / npw2] += 1;

	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = result;
		result += temp;
	}

	for (ii = 0; ii < size; ii++)
	{
		array[count[(copy[ii] % npw1) / npw2]] = copy[ii];
		count[(copy[ii] % npw1) % npw2] += 1;
	}

	free(copy);
	return (sort);
}

/**
 * pow_10 - get power of 10
 * @power: power of 10
 * Return: result of pow_10
 */
unsigned int pow_10(unsigned int power)
{
	unsigned int i, result;

	result = 1;

	for (i = 0; i < power; i++)
	{
		result *= 10;
	}
	return (result);
}
