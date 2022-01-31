
// sa, ab, ss

#include "push_swap.h"

void swap(stack *stack)
{
    int temp;

    if (stack->size > 1)
    {
        temp = stack->stack[0];
        stack->stack[0] = stack->stack[1];
        stack->stack[1] = temp;
    }
}
void swap_stack(stack *a, stack *b, char *instruction)
{
    if (instruction[1] == 'a')
        swap(a);
    if (instruction[1] == 'b')
        swap(b);
    if (instruction[1] == 's')
    {
        swap(a);
        swap(b);
    }
    printf("%s\n", instruction);
}

//: push a - take the first element at the top of b and put it at the top of a. Donothing if b is empty.

void push_stack(stack *a, stack *b, char *instruction)
{

    /*
    sa :
    input : a = [4, 1, 2, 3, 4, null];
            b = [1, 5, null, null, null, null];
    output: a = [3, 2, 3, 4, null, null]
            b = [2, 1, 5]
    */
    stack *stack_a;
    stack *stack_b;
    int temp;

    stack_a = a;
    stack_b = b;
    if (instruction[1] == 'b')
    {
        stack_a = b;
        stack_b = a;
    }
    if (stack_b->size)
    {
        temp = stack_b->stack[0];
        shift(stack_b);
        append(stack_a, temp);
        printf("%s\n", instruction);
    }
}

void rotate(stack *stack, int reverse)
{
    int temp;
    if (stack->size > 1 && !reverse)
    {
        temp = stack->stack[0];
        shift(stack);
        stack->stack[stack->size] = temp;
        stack->size += 1;
    }
    else if (stack->size > 1 && reverse)
    {
        temp = stack->stack[stack->size - 1];
        stack->size -= 1;
        append(stack, temp);
    }
}
void rotate_stack(stack *a, stack *b, char *instruction)
{
    int r;
    int i;
    
    r = 0;
    i = 1;
    if(strlen(instruction) == 3)
    {
        r = 1;
        i = 2;
    }
    if (instruction[i] == 'a' || instruction[i] == 't')
       rotate(a, r);
    if (instruction[i] == 'b')
        rotate(b, r);
    if (instruction[i] == 'r')
    {
        rotate(a, r);
        rotate(b, r);
    }
    if (instruction[i] != 't')
        printf("%s\n", instruction);

}

// pop element: delete element from the top of array
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

// append : add element to the top of the array

void append(stack *stack, int n)
{
    int i;
    stack->size += 1;
    i = stack->size;
    while(i > 0)
    {
        stack->stack[i] = stack->stack[i - 1];
        i--;
    }
    stack->stack[0] = n;
}


