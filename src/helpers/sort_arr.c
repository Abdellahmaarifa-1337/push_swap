/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:21:17 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:22:09 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	j;
	int	temp;
	int	i;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if ((arr)[j] > (arr)[j + 1])
			{
				temp = (arr)[j + 1];
				(arr)[j + 1] = (arr)[j];
				(arr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}
