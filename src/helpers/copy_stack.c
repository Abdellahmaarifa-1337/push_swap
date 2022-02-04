/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:09:25 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:09:31 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack	*copy_stack(stack *a)
{
	stack	*temp;
	int		i;
	int		*temp_arr;

	temp = (stack *)malloc(sizeof(stack));
	temp_arr = (int *)malloc(sizeof(int) * a->size);
	i = 0;
	while (i < a->size)
	{
		temp_arr[i] = a->stack[i];
		i++;
	}
	temp->stack = temp_arr;
	temp->size = a->size;
	return (temp);
}
