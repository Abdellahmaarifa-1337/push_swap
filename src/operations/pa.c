/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:23:21 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:27:46 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *a, t_stack *b, int print)
{
	int	temp;

	if (push_top(a, b) && print)
		ft_putstr("pa\n");
	return (1);
}
