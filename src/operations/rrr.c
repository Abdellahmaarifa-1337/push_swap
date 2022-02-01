#include "../push_swap.h"

void rrr(stack *a, stack *b)
{
	int i;
	int j;

	i = rotate_stack_reverse(a);
	j = rotate_stack_reverse(b);
	if (i  || j)
		ft_putstr("rrr\n");	
}