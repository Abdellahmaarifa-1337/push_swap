/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:15:31 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:16:26 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(stack *a)
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
		if (a->stack[i] == arr[0])
			break ;
		i++;
	}
	free(arr);
	return (i);
}
