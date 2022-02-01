#include "../push_swap.h"

void ss(stack *a, stack *b)
{
	int i;
	int j;

	i = swap_top(a);	
	j = swap_top(b);
	if (i || j)
		ft_putstr("ss\n");
}
