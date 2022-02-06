/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:56:44 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/06 14:05:13 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_best(t_stack *a, t_stack *b)
{
	t_moves	*best_moves;

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

int	push_not_lis(t_stack *a, t_lis *lis_temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		if (!is_in_lis(lis_temp, a->stack[i]))
			break ;
		i++;
	}
	j = a->size - 1;
	while (j >= 0)
	{
		if (!is_in_lis(lis_temp, a->stack[j]))
			break ;
		j--;	
	}
	j = a->size - j; //rra
	if (j <= i)
		i = -j;
	//printf("k == %d\n", k);
	return (i);
}

void	sort_500(t_stack *a, t_stack *b)
{
	t_lis	*lis_temp;
	// t_lis	*lis_temp_a;

	int		min_index;
	int		min_a;
	// int		i;
	// int		k;
	// int count = 0;
	lis_temp = get_lis(a);
	while (a->size > lis_temp->size)
	{
		// i = push_not_lis(a, lis_temp);
		// k = absolute(i);
		// while (k > 0)
		// {
		// 	if (i > 0)
		// 	{
		// 		ra(a, 1);
		// 	}
		// 	else
		// 	{
		// 		rra(a, 1);
		// 	}
		// 	k--;
		// }
		while (is_in_lis(lis_temp, a->stack[0]))
		{
			ra(a, 1);
		}
		pb(a, b, 1);
		//printf("size of the lis %d\n", lis_temp_a->size);
	}
	free(lis_temp->arr);
	free(lis_temp);
	while (b->size)
		push_best(a, b);
	min_index = find_min(a);
	min_a = a->stack[min_index];
	while (a->stack[0] != min_a)
	{
		if (min_index <= a->size / 2)
			ra(a, 1);
		else
			rra(a, 1);
		//   rra(a, 1);
	}
}
