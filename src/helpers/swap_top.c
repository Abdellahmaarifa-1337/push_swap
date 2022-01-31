#include "../push_swap.h"

int swap_top(stack *stack)
{
	int temp;

    if (stack->size > 1)
    {
        temp = stack->stack[0];
        stack->stack[0] = stack->stack[1];
        stack->stack[1] = temp;
		return (1);
    }
	return (0);
}