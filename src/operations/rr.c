#include "../push_swap.h"

int rr(stack *a, stack *b, int print)
{
	int i;
	int j;

	i = rotate_stack(a);
	j = rotate_stack(b);

	if ((i || j) && print)
		ft_putstr("rr\n");	
	return 1;
}