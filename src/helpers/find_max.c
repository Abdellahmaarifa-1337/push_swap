#include "../push_swap.h"

int find_max(int *arr, int size, int max)
{
	int k = 0;
	int i = 0;
	int j;
	while (k < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[j] > arr[i] && max)
				i = j;
			if (arr[j] < arr[i] && !max)
				i = j;
			j++;
		}
		k++;
	}
	return i;
}