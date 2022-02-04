/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:27:36 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:29:02 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//fuctions_table functions[] = {&foo, &bar};
int	proccess_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (!ft_strncmp(instruction, "pa\n", 3))
		return (pa(a, b, 0));
	if (!ft_strncmp(instruction, "pb\n", 3))
		return (pb(a, b, 0));
	if (!ft_strncmp(instruction, "ra\n", 3))
		return (ra(a, 0));
	if (!ft_strncmp(instruction, "rb\n", 3))
		return (rb(b, 0));
	if (!ft_strncmp(instruction, "rr\n", 3))
		return (rr(a, b, 0));
	if (!ft_strncmp(instruction, "rra", 3))
		return (rra(a, 0));
	if (!ft_strncmp(instruction, "rrb", 3))
		return (rrb(b, 0));
	if (!ft_strncmp(instruction, "rrr", 3))
		return (rrr(a, b, 0));
	if (!ft_strncmp(instruction, "sa\n", 3))
		return (sa(a, 0));
	if (!ft_strncmp(instruction, "sb\n", 3))
		return (sb(b, 0));
	if (!ft_strncmp(instruction, "ss\n", 3))
		return (ss(a, b, 0));
	return (0);
}

void	print_stack(t_stack *a, char stack)
{
	int	i;

	i = 0;
	while (i < a->size)
		printf("%d\n", a->stack[i++]);
	printf("-------\nstack %c\n", stack);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	if (ac == 1)
		return (0);
	error_checker(ac, av);
	a = init_stack(ac, av);
	b = (t_stack *)malloc(sizeof(t_stack));
	b->stack = (int *)malloc(sizeof(int) * (ac));
	b->size = 0;
	instruction = get_next_line(0, 3);
	while (instruction && instruction[0] != '\n')
	{
		if (!proccess_instruction(a, b, instruction))
			throw_err();
		instruction = get_next_line(0, 3);
	}
	if (is_sorted(a->stack, a->size) && !(b->size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
