/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:19:22 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:27:14 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_stack_reverse(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->stack[stack->size - 1];
		stack->size -= 1;
		append(stack, temp);
		return (1);
	}
	return (0);
}
