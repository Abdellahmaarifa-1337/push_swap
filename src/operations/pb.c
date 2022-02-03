#include "../push_swap.h"

int pb(stack *a, stack *b, int print)
{ 
    int temp;

    if (push_top(b, a) && print)
		ft_putstr("pb\n");
	return 1;
}