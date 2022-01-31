#include "../push_swap.h"

void rotate_stack_reverse(stack *stack)
{
	int temp;

	temp = stack->stack[stack->size - 1];
	stack->size -= 1;
	append(stack, temp);
}