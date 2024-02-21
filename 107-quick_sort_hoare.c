#include "sort.h"

/**
 * quick_sort_hoare - sorting using quick sort
 * @array: input array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare(array, size, 0, size - 1);
}

/**
 * hoare - implementation of quick sort
 * @array: input array
 * @size: size of array
 * @left: start index
 * @right: end index
 */
void hoare(int *array, size_t size, int left, int right)
{
	int temp;

	if (right - left > 0)
	{
		temp = subhoare(array, size, left, right);
		hoare(array, size, left, temp - 1);
		hoare(array, size, temp, right);
	}
}
/**
 * subhoare - subset of array
 * @array: input array
 * @size: size of array
 * @left: start index
 * @right: end index
 * Return: result
 */
int subhoare(int *array, size_t size, int left, int right)
{
	int pv, below, above;

	pv = array[right];

	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pv);

		do {
			below--;
		} while (array[below] > pv);

		if (above < below)
		{
			swap_hoare(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * swap_hoare - swap
 * @i: first element
 * @ii: second element
 */
void swap_hoare(int *i, int *ii)
{
	int tmp;

	tmp = *i;
	*i = *ii;
	*ii = tmp;
}
