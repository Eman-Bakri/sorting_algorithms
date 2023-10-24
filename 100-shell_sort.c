#include "sort.h"

/**
 * shell_sort - Function implementing Shell sort algorithm
 * to sort int array in ascending order.
 * @array: array of ints.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int holder;
	size_t gap, a, b;

	if (array == NULL || !size)
		return;

	for (gap = _Knuthmax(size); gap; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			holder = array[a];
			for (b = a; b > gap - 1 && array[b - gap] > holder; b -= gap)
				array[b] = array[b - gap];
			array[b] = holder;
		}
		print_array(array, size);
	}
}

/**
 * _Knuthmax - return max Knuth gap
 * @size: Array size.
 *
 * Return: the max gap size.
 */
size_t _Knuthmax(size_t size)
{
	size_t num;

	num = 1;
	while (num < size)
		num = num * 3 + 1;
	return ((num - 1) / 3);
}
