/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:22:59 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:27:35 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_top(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = temp;
		return (1);
	}
	return (0);
}
