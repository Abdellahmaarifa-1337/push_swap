#include "../push_swap.h"

int calc_moves_to_b(stack *b, int elm)
{
    int i = 0;
    while(i < b->size)
    {
        if(b->stack[i] == elm)
            break;
        i++;
    }
    if (i <= b->size / 2)
        return i;
    else
        return i - b->size;
}

int calc_moves_to_a(stack *a, int elm)
{
    int less_then_elm;
    less_then_elm = smallest_before_x(a, elm);
    // printf("lesser: %d\n", a->stack[less_then_elm]);
    if (less_then_elm == -1)
        return 0;
    int i = 0;
    while(i < a->size)
    {
        if(a->stack[i] == a->stack[less_then_elm])
            break;
        i++;
    }
    if (i < a->size / 2)
        return i + 1;
    else
        return i - a->size + 1;
}
moves *calc_best_moves(stack *a, stack *b)
{
    moves *push_moves;
    push_moves = (moves *)malloc(sizeof(moves));
    push_moves->to_a = a->size * 2;
    push_moves->to_b = a->size * 2;
    int i = 0;
    while(i < b->size)
    {
        int to_b = calc_moves_to_b(b, b->stack[i]);
        // printf("moves b >> %d for %d\n", to_b, b->stack[i]);
        int to_a = calc_moves_to_a(a, b->stack[i]);
        // printf("moves a >> %d for %d\n", to_a, b->stack[i]);

        if ((absolute(to_b) + absolute(to_a)) < (absolute(push_moves->to_a) + absolute(push_moves->to_b)))
        {
            push_moves->to_a = to_a;
            push_moves->to_b = to_b;
            push_moves->index = i;
        }
        i++;
    }
    return push_moves;
}

int smallest_before_x(stack *a, int elm)
{
    int index;
    
    int *a_sorted = copy_sort_stack(a, elm);
    // printf("-------------sorted------------");
    // int h = 0;
    // while(h < a->size + 1)
    // {
    //     printf("%d\n", a_sorted[h]);
    //     h++;
    // }
    //     printf("-------------wnd------------");

    int i = 0;
    while(i < a->size + 1)
    {
        if (a_sorted[i] == elm)
            break;
        i++;
    }
    if(i == 0)
        return -1;
    
    index = i - 1;
    i = 0;
    while (i < a->size)
    {
        if (a->stack[i] == a_sorted[index])
            break;
        i++;
    }
    // printf("smll = %d %d %d\n",a->stack[i], elm, a->stack[i]);
    return i;
}

