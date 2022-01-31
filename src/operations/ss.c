#include "../push_swap.h"

void ss(stack *a, stack *b)
{
	if (swap_top(a) || swap_top(b))
		ft_putstr("ss\n");
}
