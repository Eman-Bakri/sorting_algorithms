#include "sort.h"

/**
 * selection_sort - Function implementing selection sort algorithm
 * to sort int array in ascending order.
 * @array: array of ints to sort.
 * @size: Size of the array.
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, m;
	/*temporary space holder to swap*/
	int holder;

	if (array == NULL || !size)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = size - 1, m = a + 1; b > a; b--)
		{
			if (array[b] < array[m])
				m = b;
		}
		if (array[a] > array[m])
		{
			holder = array[a];
			array[a] = array[m];
			array[m] = holder;
			print_array(array, size);
		}
	}
}
