#include "../push_swap.h"
#include <stdio.h>
int rotate_stack_reverse(stack *stack)
{
	if (stack->size > 1)
	{
		int temp;
		temp = stack->stack[stack->size - 1];
		stack->size -= 1;
		append(stack, temp);
		return (1);
	}
	return (0);
}