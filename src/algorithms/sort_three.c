#include "../push_swap.h"

void sort_three(stack *a, stack *b)
{
	int i = find_max(a);
	if (i == 0)
	{
		ra(a);
		if (a->stack[0] > a->stack[1])
			sa(a);
	}
	else if (i == 1 && a->stack[2] < a->stack[0])
		rra(a);
	else if (i == 1)
	{
		sa(a);
		ra(a);
	}
	else if (a->stack[0] > a->stack[1])
		sa(a);
}