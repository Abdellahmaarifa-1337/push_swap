#include "../push_swap.h"

void rotate_stack(stack *stack)
{
	int temp;
	temp = stack->stack[0];
	shift(stack);
	stack->stack[stack->size] = temp;
	stack->size += 1;
}