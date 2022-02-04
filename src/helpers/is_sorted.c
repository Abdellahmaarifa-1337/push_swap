/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:18:24 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:18:45 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			continue ;
		}
		break ;
	}
	if (i == size - 1)
		return (1);
	return (0);
}
