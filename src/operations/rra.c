#include "../push_swap.h"

int rra(stack *a, int print)
{
	if (rotate_stack_reverse(a) && print)
		ft_putstr("rra\n");	
	return 1;
}