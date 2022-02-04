/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:20:17 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:27:19 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_stack(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->stack[0];
		shift(stack);
		stack->stack[stack->size] = temp;
		stack->size += 1;
		return (1);
	}
	return (0);
}
