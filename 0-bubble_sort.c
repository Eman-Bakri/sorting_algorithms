#include "sort.h"

/**
 * bubble_sort - Function implementing Bubble sort algorithm
 * to sort int array in ascending order.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	/*temporary space holder to swap*/
	int holder;

	if (array == NULL || !size)
		return;

	for (a = 0; a < size; a++)
	{
		/*To compare elements*/
		for (b = 0; b < size -1; b++)
		{
			if (array[b] > array[b + 1])
			{
				holder = array[b];
				array[b] = array[b + 1];
				array[b + 1] = holder;
				print_array(array, size);
			}
		}
	}
}
