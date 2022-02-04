/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:25:03 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:28:06 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rr(t_stack *a, t_stack *b, int print)
{
	int	i;
	int	j;

	i = rotate_stack(a);
	j = rotate_stack(b);
	if ((i || j) && print)
		ft_putstr("rr\n");
	return (1);
}
