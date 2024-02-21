#include "sort.h"

/**
 * shell_sort - sorting elements of array using shell sort
 * @array: input array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gp = 1, i, ii;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gp < size / 3)
		gp = gp * 3 + 1;

	while (gp >=  1)
	{
		for (i = gp; i < size; i++)
		{
			temp = array[i];
			ii = i;

			while (ii >=  gp && array[ii - gp] > temp)
			{
				array[ii] = array[ii - gp];
				ii -= gp;
			}
			array[ii] = temp;
		}
		gp = gp / 3;
		print_array(array, size);
	}
}
