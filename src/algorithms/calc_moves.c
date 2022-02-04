/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:49:30 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 11:56:24 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_moves_to_b(stack *b, int elm)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->stack[i] == elm)
			break ;
		i++;
	}
	if (i <= b->size / 2)
		return (i);
	else
		return (i - b->size);
}

int	calc_moves_to_a(stack *a, int elm)
{
	int	less_then_elm;
	int	i;

	less_then_elm = smallest_before_x(a, elm);
	if (less_then_elm == -1)
		return (0);
	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == a->stack[less_then_elm])
			break ;
		i++;
	}
	if (i < a->size / 2)
		return (i + 1);
	else
		return (i - a->size + 1);
}

moves	*calc_best_moves(stack *a, stack *b)
{
	moves	*push_moves;
	int		i;
	int		to_b;
	int		to_a;

	push_moves = (moves *)malloc(sizeof(moves));
	push_moves->to_a = a->size * 2;
	push_moves->to_b = a->size * 2;
	i = 0;
	while (i < b->size)
	{
		to_b = calc_moves_to_b(b, b->stack[i]);
		to_a = calc_moves_to_a(a, b->stack[i]);
		if ((absolute(to_b) + absolute(to_a))
			< (absolute(push_moves->to_a) + absolute(push_moves->to_b)))
		{
			push_moves->to_a = to_a;
			push_moves->to_b = to_b;
			push_moves->index = i;
		}
		i++;
	}
	return (push_moves);
}

int	smallest_before_x(stack *a, int elm)
{
	int	index;
	int	*a_sorted;
	int	i;

	a_sorted = copy_sort_stack(a, elm);
	i = 0;
	while (i < a->size + 1)
	{
		if (a_sorted[i] == elm)
			break ;
		i++;
	}
	if (i == 0)
		return (-1);
	index = i - 1;
	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == a_sorted[index])
			break ;
		i++;
	}
	return (i);
}
