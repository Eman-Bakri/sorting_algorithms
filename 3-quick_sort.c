#include "sort.h"

/**
 * quick_sort - Function implementing Quick sort algorithm
 * to sort int array in ascending order.
 * @array: array of ints.
 * @size: Size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	_sortquick(array, size, 0, size - 1);
}

/**
 * _sortquick - quicksort through recursion and partitioning.
 * @array: array of ints.
 * @size: Size of the array.
 * @left: The index at the beginning of the subset.
 * @right: The index at the end of the subset.
 *
 */
void _sortquick(int *array, size_t size, ssize_t left, ssize_t right)
{
	size_t subset;

	if (left < right)
	{
		subset = _partitionlomuto(array, size, left, right);
		_sortquick(array, size, left, subset - 1);
		_sortquick(array, size, subset + 1, right);
	}
}

/**
 * _partitionlomuto - create a subset of array by partitioning.
 * @array: An array of ints.
 * @size: Size of array.
 * @left: The index at the beginning of the subset.
 * @right: The index at the end of the subset.
 *
 * Return: size_t pivot location.
 */
size_t _partitionlomuto(int *array, size_t size, ssize_t left, ssize_t right)
{
	int pivot = array[right], a, b;

	for (a = b = left; b < right; b++)
	{
		if (array[b] < pivot)
			_intswap(array, size, &array[b], &array[a++]);
	}
	_intswap(array, size, &array[a], &array[right]);

	return (a);
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
	int holder;

	holder = *x;
	*x = *y;
	*y = holder;
	print_array((const int *)array, size);
}

