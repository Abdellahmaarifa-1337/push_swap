/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:18:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:19:14 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_top(stack *stack_1, stack *stack_2)
{
	int	temp;

	if (stack_2->size)
	{
		temp = stack_2->stack[0];
		shift(stack_2);
		append(stack_1, temp);
		return (1);
	}
	return (0);
}
