#include "../push_swap.h"

int rb(stack *b, int print)
{
	if (rotate_stack(b) && print)
		ft_putstr("rb\n");	
	return 1;
}