#include "../push_swap.h"

int rrr(stack *a, stack *b, int print)
{
	int i;
	int j;

	i = rotate_stack_reverse(a);
	j = rotate_stack_reverse(b);
	if ((i  || j) && print)
		ft_putstr("rrr\n");	
	return 1;
}