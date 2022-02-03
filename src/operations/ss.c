#include "../push_swap.h"

int ss(stack *a, stack *b, int print)
{
	int i;
	int j;

	i = swap_top(a);	
	j = swap_top(b);
	if ((i || j) && print)
		ft_putstr("ss\n");
	return (1);
}
