#ifndef __SORT_H__
#define __SORT_H__

/***********Header_files*****/
#include <stdio.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/********Functions******/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *xp, int *yp);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

void quick_sort(int *array, size_t size);
void quick_sort_recu(int *array, int low, int high, size_t size);
int lpartition(int *array, int low, int high, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void merge_recur(int *subarray, int *temp, size_t high, size_t low);
void merge_subarray(int *subarray, int *temp, size_t high,
					size_t middle, size_t low);

void heap_sort(int *array, size_t size);
void mkheap(int *array, size_t size);
void fxheap(int *array, size_t root, size_t end, size_t size);

void radix_sort(int *array, size_t size);
unsigned int count_sort(int *array, size_t size, unsigned int number);
unsigned int pow_10(unsigned int power);

void bitonic_sort(int *array, size_t size);
void bitonic(int array[], int low, int elements, int sorted, int size);
void merge_bitonic(int array[], int low, int elements, int sorted);
void swap_bitonic(int array[], int element1, int element2, int sorted);

void quick_sort_hoare(int *array, size_t size);
void hoare(int *array, size_t size, int left, int right);
int subhoare(int *array, size_t size, int left, int right);
void swap_hoare (int *i, int *ii);

#endif /* __SORT_H__ */
