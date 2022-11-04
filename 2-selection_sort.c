#include "sort.h"


/**
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i_of_min;
	int arr_min, i = 0, j;

	while(i < size - 1)
	{
		arr_min = array[i];
		for(j=i; j<size; j++)
		{
			if (array[j] < arr_min)
			{
				arr_min = array[j];
				i_of_min = j;
			}
		}
		
		array[i_of_min] = array[i];
		array[i] = arr_min;
		print_array(array, size);
		i++;
	}
}
