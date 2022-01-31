#include "../push_swap.h"

void shift(stack *stack)
{
    int i;
    i = 0;
    while(i < stack->size)
    {
       stack->stack[i] = stack->stack[i + 1];
       i++; 
    }
    stack->size -= 1;
}
