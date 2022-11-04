#include "sort.h"

/**
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, newn, i;
	int temp;

	while(size > 1)
	{
		newn = 0;
		for(i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				newn = i;

				print_array(array, n);
			}
		}
		size = newn;
	}
}
