/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:15:19 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:15:22 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(stack *a)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * a->size);
	i = 0;
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
	sort_arr(arr, a->size);
	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == arr[a->size - 1])
			break ;
		i++;
	}
	free(arr);
	return (i);
}
