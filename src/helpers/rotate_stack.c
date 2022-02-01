#include "../push_swap.h"

int rotate_stack(stack *stack)
{
	if (stack->size > 1)
	{
		int temp;
		temp = stack->stack[0];
		shift(stack);
		stack->stack[stack->size] = temp;
		stack->size += 1;
		return (1);
	}
	return (0);
}