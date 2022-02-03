#include "../push_swap.h"


static void push_min(stack *a, stack *b, int index)
{
	int min;
	
	min = a->stack[index];
	while(a->stack[0] != min)
	{
		if (index < a->size)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
}

void sort_five(stack *a, stack *b)
{
	push_min(a, b, find_min(a));
	push_min(a, b, find_min(a));
	sort_three(a, b);
	pa(a, b, 1);
	pa(a, b, 1);
}