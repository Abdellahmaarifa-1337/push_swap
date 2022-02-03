#include "../push_swap.h"

int rrb(stack *b, int print)
{
	if (rotate_stack_reverse(b) && print)
		ft_putstr("rrb\n");	
	return 1;
}