#include "sort.h"


/**
 * partition - a function to partition an array and select a pivot
 * point then swap out values if it finds a value on the wrong side
 * of the pivot
 * @A: the begginning of the (sub)array
 * @lo: the index of the probable smallest integer in the array or
 * sub-array
 * @hi: the index of the largest probable integer in the (sub)array
 * @size: the length of our array, used in printing
 *
 * Return: The pivot index
 */
int partition(int *A, int lo, int hi, size_t size)
{
	int i, j, pivot, temp;

	pivot = A[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{

		if (A[j] <= pivot)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	i++;
	temp = A[i];
	A[i] = A[hi];
	A[hi] = temp;
	print_array(A, size);
	return (i);
}

/**
 * lomuto_quicksort - a function that uses the lomuto partitioning
 * scheme to sort an array of integers iteratively
 * @A: our array of integers
 * @lo: the index of the probable smallest integer in the array or
 * sub-array
 * @hi: the index of the largest probable integer in the (sub)array
 * @size: the length of our array, used in printing
 */
void lomuto_quicksort(int *A, int lo, int hi, size_t size)
{
	int p_index;

	if ((lo > hi) || (lo < 0))
		return;


	/* Partition array and get pivot index */
	p_index = partition(A, lo, hi, size);
	lomuto_quicksort(A, lo, p_index - 1, size);
	lomuto_quicksort(A, p_index + 1, hi, size);
}

/**
 * quick_sort - a function to get values and asses aarray before
 * calling lomuto_quick sort to sort the array
 * @array: an array of integers
 * @size: the length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size >= 2)
		lomuto_quicksort(array, 0, size - 1, size);
}
