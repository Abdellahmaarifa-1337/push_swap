/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:16:55 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:17:18 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack	*init_stack(int ac, char **av)
{
	stack	*a;
	int		i;

	a = (stack *)malloc(sizeof(stack));
	a->stack = (int *)malloc(sizeof(int) * (ac));
	i = 0;
	while (i < ac - 1)
	{
		a->stack[i] = atoi(av[i + 1]);
		i++;
	}
	a->size = ac - 1;
	return (a);
}
