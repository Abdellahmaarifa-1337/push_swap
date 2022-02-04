/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_sorted_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:08:30 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*copy_sort_stack(stack *a, int elm)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * a->size + 1);
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
	arr[i] = elm;
	sort_arr(arr, a->size + 1);
	return (arr);
}
