#include "../push_swap.h"

int push_top(stack *stack_1, stack *stack_2)
{
	int temp;

	if (stack_2->size)
    {
        temp = stack_1->stack[0];
        shift(stack_2);
        append(stack_1, temp);
		return (1);
    }
	return (0);
}