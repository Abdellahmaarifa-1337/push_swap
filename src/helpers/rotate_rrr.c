/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:52:39 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:52:53 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_rrr(t_stack *a, t_stack *b, t_moves *best_moves)
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
