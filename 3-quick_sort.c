#include "sort.h"
#include <stdio.h>

int partition(int *A, int lo, int hi)
{
	int i, j, pivot, temp;

	pivot = A[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{

		if(A[j]<=pivot)
		{
			printf("____________IN_LOOP___________\n");
			print_array(A, hi + 1);
			i ++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			print_array(A, hi + 1);
			printf("____________END_IN_LOOP___________\n");
		}
	}
	i++;
	printf("____________OUT_LOOP___________\n");
	print_array(A, hi + 1);
	temp = A[i];
	A[i] = A[hi];
	A[hi] = temp;
	print_array(A, hi + 1);
	printf("____________END_OUT_LOOP___________\n");

	return (i);
}


void lomuto_quicksort(int *A, int lo, int hi)
{
	int p_index;
	if ((lo > hi) || (lo < 0))
		return;

	p_index = partition(A, lo, hi);
	printf("-----lower--half-%d-%d-\n", lo, hi);
	lomuto_quicksort(A, lo, p_index -1);
	printf("-----upper-half--%d-%d-\n", lo, p_index -1);
	lomuto_quicksort(A, p_index + 1, hi);
}




/**
 *
 */
void quick_sort(int *array, size_t size)
{
	lomuto_quicksort(array, 0, size-1);
}
