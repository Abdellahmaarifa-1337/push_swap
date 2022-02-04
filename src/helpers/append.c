/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:27 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:07:47 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append(stack *stack, int n)
{
	int	i;

	stack->size += 1;
	i = stack->size;
	while (i-- > 0)
		stack->stack[i] = stack->stack[i - 1];
	stack->stack[0] = n;
}
