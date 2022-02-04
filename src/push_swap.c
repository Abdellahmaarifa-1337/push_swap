/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:38:33 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 12:39:53 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(stack *a, char stack)
{
	int	i;

	i = 0;
	while (i < a->size)
		printf("%d\n", a->stack[i++]);
	printf("-------\nstack %c\n", stack);
}

int	main(int ac, char **av)
{
	stack	*a;
	stack	*b;

	if (ac < 2)
		return (0);
	error_checker(ac, av);
	a = init_stack(ac, av);
	b = (stack *)malloc(sizeof(stack));
	b->stack = (int *)malloc(sizeof(int) * (ac));
	b->size = 0;
	if (!is_sorted(a->stack, a->size))
		sort_stack(a, b);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
