/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:16:55 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:26:46 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
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
