#include "sort.h"

/**
 * heap_sort - sorting using heap.
 * @array: input array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;

	mkheap(array, size);
	end = size - 1;

	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		fxheap(array, 0, end, size);
	}
}

/**
 * mkheap - setting heap for unsorted
 * @array: input array
 * @size: size of array
 */
void mkheap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		fxheap(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
 * fxheap - fix
 * @array: input array
 * @root: root of the heap
 * @end: last index of heap
 * @size: size of array
 */
void fxheap(int *array, size_t root, size_t end, size_t size)
{
	size_t left, right, swap;
	int temp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}
