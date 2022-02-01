#include "../push_swap.h"

void rr(stack *a, stack *b)
{
	int i;
	int j;

	i = rotate_stack(a);
	j = rotate_stack(b);

	if (i || j)
		ft_putstr("rr\n");	
}