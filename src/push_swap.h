#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct stacks {
	int *stack;
	int size;
} stack;

typedef struct LIS {
	int *arr;
	int size;
} lis;

typedef struct moves {
	int to_b;
	int to_a;
	int index;
} moves;

// HELPERS
void ft_putstr(char *s);
int swap_top(stack *stack);
int push_top(stack *stack_1, stack *stack_2);
void shift(stack *stack);
void append(stack *stack, int n);
int rotate_stack(stack *stack);
int rotate_stack_reverse(stack *stack);
int str_isdigit(char *s);
int find_max(stack *a);
stack *copy_stack(stack *a);
int find_min(stack *a);
lis *find_LIS(int *arr, int size);
int is_in_lis(lis *lis_arr, int n);
void puch_min_max(stack *a, stack *b, int max);
void sort_arr(int *arr, int size);
int *copy_sort_stack(stack *a, int elm);
int absolute(int a);
int is_sorted(int *arr, int size);
int	ft_strncmp(const char	*s1, const char	*s2, size_t	n);
stack *init_stack(int ac, char **av);
int	ft_isdigit(int c);
int	ft_atoi(const char	*str);
//GET NEXT LINE
char	*ft_substr(char *s, unsigned int start, size_t len);
int		get_nl(const char *s);
char	*ft_strdup(const char	*src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, int buffer_size);
char	*get_line(char **s);


// OPERATION
int sa(stack *a, int print);
int sb(stack *b, int print);
int ss(stack *a, stack *b, int print);
int pa(stack *a, stack *b, int print);
int pb(stack *a, stack *b, int print);
int ra(stack *a, int print);
int rb(stack *b, int print);
int rr(stack *a, stack *b, int print);
int rra(stack *a, int print);
int rrb(stack *b, int print);
int rrr(stack *a, stack *b, int print);

//error checker 
int error_checker(int ac, char **av);

//sorting algo
void sort_stack(stack *a, stack *b);
void sort_three(stack *a, stack *b);
void sort_five(stack *a, stack *b);
void sort_100(stack *a, stack *b);
int calc_moves_to_b(stack *b, int elm);
int calc_moves_to_a(stack *a, int elm);
moves *calc_best_moves(stack *a, stack *b);
int smallest_before_x(stack *a, int elm);

//temprary functions
void print_stack(stack *a, char stack);

#endif