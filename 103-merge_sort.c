#include "sort.h"

/**
 * merge_sort - Function implementing Merge sort algorithm
 * to sort int array in ascending order.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t a;
	int *nb;

	if (array == NULL || !size)
		return;

	nb = malloc(sizeof(int) * size);
	if (nb == NULL)
		return;
	for (a = 0; a < size; a++)
		nb[a] = array[a];

	_topdownmerge(nb, 0, size, array);
	free(nb);
}

/**
 * _topdownmerge - Implement the top down merge sort recursively.
 * @array: Array of ints.
 * @buff: To store the sorted array.
 * @begin: The beggining index.
 * @end: The end index.
 */
void _topdownmerge(int *array, size_t begin, size_t end, int *buff)
{
	size_t midpnt;

	midpnt = (begin + end) / 2;
	if (end - begin < 2)
	{
		return;
	}
	_topdownmerge(buff, begin, midpnt, array);
	_topdownmerge(buff, midpnt, end, array);
	_comparemerge(array, begin, end, buff);
}

/**
 * _comparemerge - to compare.
 * @array: Array of ints.
 * @buff: To store the sorted array.
 * @begin: The beggining index.
 * @end: The end index.
 */
void _comparemerge(int *array, size_t begin, size_t end, int *buff)
{
	size_t a = begin;
	size_t b, m, midpnt;

	b = midpnt = (begin + end) / 2;
	printf("Merging...\n[left]: ");
	print_array(array + begin, midpnt - begin);

	printf("[right]: ");
	print_array(array + midpnt, end - midpnt);

	for (m = begin; m < end; m++)
		if ((array[a] <= array[b] || b >= end) && a < midpnt)
			buff[m] = array[a++];
		else
			buff[m] = array[b++];

	printf("[Done]: ");
	print_array(buff + begin, end - begin);
}

