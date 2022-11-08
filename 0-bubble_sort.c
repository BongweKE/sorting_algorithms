#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort algorithm
 * @array: an array of integers
 * @size: the number of elements in the array
 *
 * Description: The array will be sorted, one pair at a time
 * until one loop through the whole array is completed
 * through every loop, the bigger number between two is sent
 * to the > direction. We keep track of the last element's
 * index given that this is the index of the last array we
 * swapped at. This helps reduce time complexity since bubble
 * sort ensures that each loop through the array moves the
 * largest element to the largest index. Therefore less
 * changes will be made, the more repetitions are done.
 *
 * No changes are made for array with size less than 2
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, newn, i;
	int temp;

	if (size < 2 || array == NULL)
		return;

	while (size > 1)
	{
		newn = 0;
		for (i = 1; i < size; i++)
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
