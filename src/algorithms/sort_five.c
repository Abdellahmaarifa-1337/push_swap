/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:05:35 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/05 13:38:00 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_min(t_stack *a, t_stack *b, int index)
{
	int	min;

	min = a->stack[index];
	while (a->stack[0] != min)
	{
		if (index < a->size / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min(a, b, find_min(a));
	push_min(a, b, find_min(a));
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
