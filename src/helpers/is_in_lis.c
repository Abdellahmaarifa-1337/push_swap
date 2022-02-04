/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:17:55 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:17:57 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_in_lis(lis *lis_arr, int n)
{
	int	i;

	i = 0;
	while (i < lis_arr->size)
	{
		if (n == lis_arr->arr[i])
			return (1);
		i++;
	}
	return (0);
}
