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
	stack *a;
	stack *b;
	
	if (ac < 2)
		return (0);
    error_checker(ac, av);
	a = init_stack(ac, av);
	b = (stack *)malloc(sizeof(stack));
    b->stack = (int *)malloc(sizeof(int) * (ac));
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
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	while (1)
	{
		
	}
    return (0);
}