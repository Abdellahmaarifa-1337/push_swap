/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:27:24 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:26 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(stack *a, stack *b, int print)
{
	int	i;
	int	j;

	i = swap_top(a);
	j = swap_top(b);
	if ((i || j) && print)
		ft_putstr("ss\n");
	return (1);
}
