#include "../push_swap.h"

stack *copy_stack(stack *a)
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    int *temp_arr;
    temp_arr = (int *)malloc(sizeof(int) * a->size);
    int i = 0;
    while(i < a->size)
    {
        temp_arr[i] = a->stack[i];
        i++;
    }
    temp->stack = temp_arr;
    temp->size = a->size;
	return temp;
}