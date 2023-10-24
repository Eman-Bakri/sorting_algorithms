#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * heap_sort - Function implementing Merge sort algorithm
 * to sort int array in ascending order.
 * @array: Array of ints.
 * @size: Size of array.
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t last;

	if (array == NULL || !size)
		return;

	_heapify(array, size);
	last = size - 1;

	while (last > 0)
	{
		_intswap(array, size, &array[last], &array[0]);
		last--;
		_siftdownheap(array, 0, last, size);
	}
}
/**
 * _heapify - heap.
 * @array: Array of ints.
 * @size: Size of array.
 */
void _heapify(int *array, size_t size)
{
	size_t begin;
	/*unsigned int i = 1;*/
	/*unsigned int t;*/

	/*t = i - 1;*/
	begin = parent(size - 1);
	while (begin > 0)
	{
		_siftdownheap(array, begin, size - 1, size);
		begin--;
	}
	while (begin == 0)
	{
		_siftdownheap(array, begin, size - 1, size);
		begin--;
	}
}
/**
 * _siftdownheap - Implement the sift down heap sort.
 * @array: Array of ints.
 * @begin: The beggining index.
 * @end: The end index.
 * @size: Size of array.
 */
void _siftdownheap(int *array, size_t begin, size_t end, size_t size)
{
	size_t rt = begin, swp, ch;

	while (leftchild(rt) <= end)
	{
		ch = leftchild(rt);
		swp = rt;
		if (array[swp] < array[ch])
			swp = ch;
		if (array[swp] < array[ch + 1] && ch + 1 <= end)
			swp = ch + 1;
		if (swp == rt)
			return;
		_intswap(array, size, &array[rt], &array[swp]);
		rt = swp;
	}
}

/**
 * _intswap - Function to swap two ints in array.
 * @x: int1 to swap.
 * @y: int2 to swap.
 * @array: array of ints.
 * @size: size of array.
 */
void _intswap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

