 	
#include "../push_swap.h"

int pa(stack *a, stack *b, int print)
{ 
    int temp;

    if (push_top(a, b) && print)
		ft_putstr("pa\n");
	return 1;
}