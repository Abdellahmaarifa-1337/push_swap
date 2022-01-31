#include "../push_swap.h"

void sort_five(stack *a, stack *b)
{
	puch_min_max(a, b, 0);
	puch_min_max(a, b, 0);
	sort_three(a, b);
	pa(a, b);
	pa(a, b);
}