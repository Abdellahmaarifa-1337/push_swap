/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_diff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:53:44 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:53:56 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_diff(t_stack *a, t_stack *b, t_moves *best_moves)
{
	int	k;

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
