#include "../push_swap.h"

int *copy_sort_stack(stack *a, int elm)
{
    int *arr;
	int i= 0;

	arr = (int *)malloc(sizeof(int) * a->size + 1);
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
    arr[i] = elm;
    sort_arr(arr, a->size + 1);
    return arr;
}