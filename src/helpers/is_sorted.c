#include "../push_swap.h"

int is_sorted(int *arr, int size)
{
	int i = 0;
	while(i < size - 1)
	{
		if(arr[i] > arr[i + 1])
		{
			i++;
			continue;
		}
		break;
	}
	if (i == size - 1)
		return 1;
	return 0;
}