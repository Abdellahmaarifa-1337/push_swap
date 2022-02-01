#include "push_swap.h"



void print_stack(stack *a, char stack)
{
    int i;
    i = 0;
    while(i < a->size)
        printf("%d\n", a->stack[i++]);
    printf("-------\nstack %c\n", stack);
}

int main(int ac, char **av)
{
    int i;
	stack *a;
	stack *b;
	a = (stack *)malloc(sizeof(stack));
	b = (stack *)malloc(sizeof(stack));
    checker(ac, av);
    a->stack = (int *)malloc(sizeof(int) * (ac));
    b->stack = (int *)malloc(sizeof(int) * (ac));
    i = 0;
    while (i < ac - 1)
	{
       	a->stack[i] = atoi(av[i + 1]);
		i++;
	}
	a->size = ac - 1;
    b->size = 0;
     //swap_stack(a, b, "as");
     //push_stack(a, b, "pb");
     //push_stack(a, b, "pb");
    // push_stack(&a, &b, "pb");
     //rotate_stack(a, b, "ra");
    // rotate_stack(&a, &b, "rrr");

	// sort the stack
	if (!is_sorted(a->stack, a->size))
		sort_stack(a, b);
	// print stacks
    // print_stack(a, 'a');
    // print_stack(b, 'b');
    return (0);
}