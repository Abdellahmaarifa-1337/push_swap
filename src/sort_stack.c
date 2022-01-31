#include "push_swap.h"

void sort_stack(stack *a, stack *b)
{
		if (a->size <= 3)
			sort_three(a, b);
		else if (a->size <= 5)
			sort_five(a, b);
		else if (a->size <= 100)
			sort_100(a, b);
		else if (a->size <= 500)
			sort_100(a, b);		
}