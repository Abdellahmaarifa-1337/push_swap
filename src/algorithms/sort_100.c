
#include <stdio.h>
#include "../push_swap.h"


static void rotate_best (stack *a, stack *b, moves *best_moves)
{
	int k;

	if (best_moves->to_a > best_moves->to_b)
	{
		k = best_moves->to_b;
		best_moves->to_a -= k;
		best_moves->to_b = 0;
	}
	else
	{
		k = best_moves->to_a;
		best_moves->to_b -= k;
		best_moves->to_a = 0;
	}
	while (k-- > 0)
		rr(a, b);
	while ((best_moves->to_a)-- > 0)
		ra(a);
	while ((best_moves->to_b)-- > 0)
		rb(b); 
}
static void rotate_best_reverse (stack *a, stack *b, moves *best_moves)
{
	int k;
	best_moves->to_a = absolute( best_moves->to_a);
	best_moves->to_b = absolute( best_moves->to_b);
	if (best_moves->to_a > best_moves->to_b)
	{
		k = best_moves->to_b;
		best_moves->to_a -= k;
		best_moves->to_b = 0;
	}
	else
	{
		k = best_moves->to_a;
		best_moves->to_b -= k;
		best_moves->to_a = 0;
	}
	while (k-- > 0)
		rrr(a,b);
	while ((best_moves->to_a)-- > 0)
		rra(a);
	while ((best_moves->to_b)-- > 0)
		rrb(b); 
}
static void push_best(stack *a, stack *b)
{
 	moves *best_moves = calc_best_moves(a, b); 
	int k;
	
	if (best_moves->to_a > 0 && best_moves->to_b > 0)
		rotate_best(a, b, best_moves);
	else if (best_moves->to_a < 0 && best_moves->to_b < 0)
		rotate_best_reverse(a, b, best_moves);
	else
	{
		k = 0;
		while(k++ < absolute(best_moves->to_b))
			if (best_moves->to_b > 0)
				rb(b);
			else
				rrb(b);
		k = 0;
		while(k++ < absolute(best_moves->to_a))
			if (best_moves->to_a > 0)
				ra(a);
			else
				rra(a);
	}
	pa(a, b);
}

static lis *get_lis(stack *a)
{
 	stack *temp;
    temp = copy_stack(a);
    int min_temp = find_min(temp);
    int min = temp->stack[min_temp];
    while (temp->stack[0] != min)
    {
        if (min_temp <= temp->size / 2)
            rotate_stack(temp);
        else
            rotate_stack_reverse(temp);
    }
    return (find_LIS(temp->stack, temp->size));
}
void sort_100(stack *a, stack *b)
{
   	lis *lis_temp;

    lis_temp = get_lis(a);
	//printf("lis size = %d\n",lis_temp->size);
    while(a->size > lis_temp->size)
    {
        while(is_in_lis(lis_temp, a->stack[0]))
            ra(a);
        pb(a, b);
    }
    while(b->size)
		push_best(a, b);
    int min_index = find_min(a);
    int min_a = a->stack[min_index];
    while(a->stack[0] != min_a)
    {
        if (min_index >= a->size / 2)
            ra(a);
        else
            rra(a);
    }
}

