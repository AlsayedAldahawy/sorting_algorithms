#include "sort.h"

/**
 * merge_sort - sorting array using merge
 * @array: input array
 * @size: size of input array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_recur(array, temp, 0, size);
	free(temp);
}

/**
 * merge_recur - do recursion for merge
 * @subarray: input subarray
 * @temp: stored result
 * @high: high index of array
 * @low: low index of array
 */
void merge_recur(int *subarray, int *temp, size_t high, size_t low)
{
	size_t middle;

	if (low - high > 1)
	{
		middle = high + (low - high) / 2;
		merge_recur(subarray, temp, high, middle);
		merge_recur(subarray, temp, middle, low);
		merge_subarray(subarray, temp, high, middle, low);
	}
}

/**
 * merge_subarray - merge subarray
 * @subarray: input subarray
 * @temp: stored result
 * @high: high index
 * @middle: middle index
 * @low: low index
 */
void merge_subarray(int *subarray, int *temp, size_t high,
					size_t middle, size_t low)
{
	size_t i, ii, iii = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + high, middle - high);

	printf("[right]: ");
	print_array(subarray + middle, low - middle);

	for (i = high, ii = middle; i < middle && ii < low; iii++)
		temp[iii] = (subarray[i] < subarray[ii]) ? subarray[i++] : subarray[ii++];

	for (; i < middle; i++)
		temp[iii++] = subarray[i];

	for (; ii < low; ii++)
		temp[iii++] = subarray[ii];

	for (i = high, iii = 0; i < low; i++)
		subarray[i] = temp[iii++];

	printf("[Done]: ");
	print_array(subarray + high, low - high);
}
