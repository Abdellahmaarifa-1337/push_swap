/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:56:44 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:53:11 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_best(t_stack *a, t_stack *b)
{
	t_moves	*best_moves;
	int		k;

	best_moves = calc_best_moves(a, b);
	if (best_moves->to_a > 0 && best_moves->to_b > 0)
		rotate_rr(a, b, best_moves);
	else if (best_moves->to_a < 0 && best_moves->to_b < 0)
		rotate_rrr(a, b, best_moves);
	else
		rotate_diff(a, b, best_moves);
	pa(a, b, 1);
	free(best_moves);
}

static t_lis	*get_lis(t_stack *a)
{
	t_stack	*temp;
	t_lis	*lis_temp;
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
	lis_temp = find_lis(temp->stack, temp->size);
	free(temp->stack);
	free(temp);
	return (lis_temp);
}

void	sort_100(t_stack *a, t_stack *b)
{
	t_lis	*lis_temp;
	int		min_index;
	int		min_a;

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
