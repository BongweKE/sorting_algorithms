#include "sort.h"

/**
 * selection_sort - a function which sorts an array using selection
 * sort algorithm implementation
 * @array: the array of integers
 * @size: the number of values in our array
 *
 * Description: We begin each iteration with the first element being the
 * supposedly smallest element in our array. We then traverse the array
 * looking for the actual smallest element and swap it out with the actual
 * smallest element.
 * After the current smallest element being placed at the beginning of the
 * array, we move on to the next index and repeat the same process
 * In essence, the smallest items in the array will be handpicked and
 * placed at the beginning in order and the search area be reduced by the
 * increase in start point index with every iteration over the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i_of_min,  i = 0, j;
	int arr_min;

	/* skip lists with size < 2  */
	if (size < 2 || array == NULL)
		return;


	while (i < size - 1)
	{
		arr_min = array[i];
		for (j = i; j < size; j++)
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
