/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:09:25 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:24:41 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*copy_stack(t_stack *a)
{
	t_stack	*temp;
	int		i;
	int		*temp_arr;

	temp = (t_stack *)malloc(sizeof(t_stack));
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
