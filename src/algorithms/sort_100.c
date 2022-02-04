/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:56:44 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:05:22 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_best(stack *a, stack *b, moves *best_moves)
{
	int	k;

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
		rr(a, b, 1);
	while ((best_moves->to_a)-- > 0)
		ra(a, 1);
	while ((best_moves->to_b)-- > 0)
		rb(b, 1);
}

static void	rotate_best_reverse(stack *a, stack *b, moves *best_moves)
{
	int	k;

	best_moves->to_a = absolute(best_moves->to_a);
	best_moves->to_b = absolute(best_moves->to_b);
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
		rrr(a, b, 1);
	while ((best_moves->to_a)-- > 0)
		rra(a, 1);
	while ((best_moves->to_b)-- > 0)
		rrb(b, 1);
}

static void	push_best(stack *a, stack *b)
{
	moves	*best_moves;
	int		k;

	best_moves = calc_best_moves(a, b);
	if (best_moves->to_a > 0 && best_moves->to_b > 0)
		rotate_best(a, b, best_moves);
	else if (best_moves->to_a < 0 && best_moves->to_b < 0)
		rotate_best_reverse(a, b, best_moves);
	else
	{
		k = 0;
		while (k++ < absolute(best_moves->to_b))
		{
			if (best_moves->to_b > 0)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		k = 0;
		while (k++ < absolute(best_moves->to_a))
		{
			if (best_moves->to_a > 0)
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
	pa(a, b, 1);
	free(best_moves);
}

static lis	*get_lis(stack *a)
{
	stack	*temp;
	lis		*lis_temp;
	int		min_temp;
	int		min;

	temp = copy_stack(a);
	min_temp = find_min(temp);
	min = temp->stack[min_temp];
	while (temp->stack[0] != min)
	{
		if (min_temp <= temp->size / 2)
			rotate_stack(temp);
		else
			rotate_stack_reverse(temp);
	}
	lis_temp = find_LIS(temp->stack, temp->size);
	free(temp->stack);
	free(temp);
	return (lis_temp);
}

void	sort_100(stack *a, stack *b)
{
	lis	*lis_temp;
	int	min_index;
	int	min_a;

	lis_temp = get_lis(a);
	while (a->size > lis_temp->size)
	{
		while (is_in_lis(lis_temp, a->stack[0]))
			ra(a, 1);
		pb(a, b, 1);
	}
	free(lis_temp->arr);
	free(lis_temp);
	while (b->size)
		push_best(a, b);
	min_index = find_min(a);
	min_a = a->stack[min_index];
	while (a->stack[0] != min_a)
	{
		if (min_index >= a->size / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
