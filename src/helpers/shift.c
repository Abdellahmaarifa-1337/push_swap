/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:20:51 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:21:12 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	shift(stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->size -= 1;
}
