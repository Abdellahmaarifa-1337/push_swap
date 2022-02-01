#include "../push_swap.h"

void append(stack *stack, int n)
{
    int i;
    stack->size += 1;
    i = stack->size;
    while(i-- > 0)
        stack->stack[i] = stack->stack[i - 1];
    stack->stack[0] = n;
}
