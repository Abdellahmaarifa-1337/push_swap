#include "../push_swap.h"

void rra(stack *a)
{
	if (rotate_stack_reverse(a))
		ft_putstr("rra\n");	
}