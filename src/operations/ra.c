#include "../push_swap.h"

int ra(stack *a, int print)
{

	if (rotate_stack(a) && print)
		ft_putstr("ra\n");	
	return 1;
}