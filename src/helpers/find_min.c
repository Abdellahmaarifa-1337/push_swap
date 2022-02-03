#include "../push_swap.h"

int find_min(stack *a)
{
    int *arr;
    arr = (int *)malloc(sizeof(int) * a->size);
    int i = 0;
    while(i < a->size)
    {
        arr[i] = a->stack[i];
        i++;
    }
    sort_arr(arr, a->size);
    i = 0;
    while(i < a->size)
    {
        if(a->stack[i] == arr[0])
            break;
        i++;
    }
	free(arr);
    return i;
}