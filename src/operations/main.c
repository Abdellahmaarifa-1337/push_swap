/*#include <stdio.h>
#include <stdlib.h>
# include "../push_swap.h"
void print_stack(stack *a, char stack)
{
    int i;
    i = 0;
    while(i < a->size)
        printf("%d\n", a->stack[i++]);
    printf("-------\nstack %c\n", stack);
}
int main()
{
	stack a;
	stack b;
	int arr[] = {1, 2, 3};
	int *arr2 = malloc(sizeof(int) * 3);
	a.stack = arr;
	a.size = 3;
	b.stack = arr2;
	b.size = 0;
	pb(&a, &b);
	pa(&a, &b);
	ra(&a);
	rra(&a);
	print_stack(&a, 'a');
	print_stack(&b, 'b');
}*/