#include "../push_swap.h"

void puch_min_max(stack *a, stack *b, int max)
{
	int i_max;
	i_max = find_max(b->stack, b->size, max);
	//printf("i_max = %d\n", i_max);
	int j = b->stack[i_max];
	if (j == b->stack[1])
	{
		sb(b);
		pa(a, b);
		return ;
	}	
	if (i_max <= (b->size / 2))
	{
		while(b->stack[0] != j)
		{
				rb(b);
		}
	}
	else
	{	
		while(b->stack[0] != j)
		{
				rrb(b);
		}
	}
	pa(a, b);
}