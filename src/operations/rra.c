/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:25:32 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:25:46 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(stack *a, int print)
{
	if (rotate_stack_reverse(a) && print)
		ft_putstr("rra\n");
	return (1);
}
