/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:40:34 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/05 17:31:37 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct stacks {
	int	*stack;
	int	size;
}	t_stack;

typedef struct LIS {
	int	*arr;
	int	size;
}	t_lis;

typedef struct moves {
	int	to_b;
	int	to_a;
	int	index;
}	t_moves;

// HELPERS
void	ft_putstr(char *s);
int		swap_top(t_stack *stack);
int		push_top(t_stack *stack_1, t_stack *stack_2);
void	shift(t_stack *stack);
void	append(t_stack *stack, int n);
int		rotate_stack(t_stack *stack);
int		rotate_stack_reverse(t_stack *stack);
int		str_isdigit(char *s);
int		find_max(t_stack *a);
t_stack	*copy_stack(t_stack *a);
int		find_min(t_stack *a);
t_lis	*find_lis(int *arr, int size);
int		is_in_lis(t_lis *lis_arr, int n);
void	puch_min_max(t_stack *a, t_stack *b, int max);
void	sort_arr(int *arr, int size);
int		*copy_sort_stack(t_stack *a, int elm);
int		absolute(int a);
int		is_sorted(int *arr, int size);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
t_stack	*init_stack(int ac, char **av);
int		ft_isdigit(int c);
int		ft_atoi(const char	*str);
void	rotate_rr(t_stack *a, t_stack *b, t_moves *best_moves);
void	rotate_rrr(t_stack *a, t_stack *b, t_moves *best_moves);
void	rotate_diff(t_stack *a, t_stack *b, t_moves *best_moves);

//GET NEXT LINE
char	*ft_substr(char *s, unsigned int start, size_t len);
int		get_nl(const char *s);
char	*ft_strdup(const char	*src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, int buffer_size);
char	*get_line(char **s);

// OPERATION
int		sa(t_stack *a, int print);
int		sb(t_stack *b, int print);
int		ss(t_stack *a, t_stack *b, int print);
int		pa(t_stack *a, t_stack *b, int print);
int		pb(t_stack *a, t_stack *b, int print);
int		ra(t_stack *a, int print);
int		rb(t_stack *b, int print);
int		rr(t_stack *a, t_stack *b, int print);
int		rra(t_stack *a, int print);
int		rrb(t_stack *b, int print);
int		rrr(t_stack *a, t_stack *b, int print);

//error checker 
int		error_checker(int ac, char **av);
void	throw_err(void);

//sorting algo
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_100(t_stack *a, t_stack *b);
int		calc_moves_to_b(t_stack *b, int elm);
int		calc_moves_to_a(t_stack *a, int elm);
t_moves	*calc_best_moves(t_stack *a, t_stack *b);
int		smallest_before_x(t_stack *a, int elm);
void	sort_500(t_stack *a, t_stack *b);
//temprary functions
void	print_stack(t_stack *a, char stack);

#endif