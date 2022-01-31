
#include <stdio.h>
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

int *copy_sort_stack(stack *a, int elm)
{
    int *arr;
	int i= 0;

	arr = (int *)malloc(sizeof(int) * a->size + 1);
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
    arr[i] = elm;
    sort_arr(arr, a->size + 1);
    return arr;
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
int absolute(int a)
{
    if (a < 0)
        return a * -1;
    return a;
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


void sort_100(stack *a, stack *b)
{
    stack *temp;
    temp = copy_stack(a);
    int min_temp = find_max(temp->stack, temp->size, 0);
    int min = temp->stack[min_temp];
    while (temp->stack[0] != min)
    {
        if (min_temp <= temp->size / 2)
            ra(temp);
        else
            rra(temp);
    }


    //just for 500


    // print_stack(temp, 't');
    lis *lis_temp;
    lis_temp = find_LIS(temp->stack, temp->size);
    // push none lis from a to b;
    // int i = 0;
    // while(i < lis_temp->size)
    // {
    //     printf("l = %d\n", lis_temp->arr[i]);
    //     i++;
    // }
    //printf("lis size: %d\n", lis_temp->size);
    //return;
    while(a->size > lis_temp->size)
    {
        while(is_in_lis(lis_temp, a->stack[0]))
            ra(a);
        pb(a, b);
        //break;
    }
    while(b->size)
    {
        //  printf("------------before--------------\n");
        // print_stack(a, 'a');
        // print_stack(b, 'b');

        moves *best_moves = calc_best_moves(a, b); 
        // printf("moves A : %d\nmoves B : %d\n best : %d\n", best_moves->to_a, best_moves->to_b, b->stack[best_moves->index]);

        int k;
        int i = 0;
        if (best_moves->to_a > 0 && best_moves->to_b > 0)
        {
            if (best_moves->to_a > best_moves->to_b)
            {
                k = best_moves->to_b;
                best_moves->to_a -= k;
                best_moves->to_b = 0;
            }
            else
            {
                k = best_moves->to_a;
                best_moves->to_b -= k;
                best_moves->to_a = 0;
            }
            while (k-- > 0)
                rr(a, b);
            while ((best_moves->to_a)-- > 0)
                ra(a);
            while ((best_moves->to_b)-- > 0)
                rb(b); 
        }
        else if (best_moves->to_a < 0 && best_moves->to_b < 0)
        {
            best_moves->to_a = absolute( best_moves->to_a);
            best_moves->to_b = absolute( best_moves->to_b);
            if (best_moves->to_a > best_moves->to_b)
            {
                k = best_moves->to_b;
                best_moves->to_a -= k;
                best_moves->to_b = 0;
            }
            else
            {
                k = best_moves->to_a;
                best_moves->to_b -= k;
                best_moves->to_a = 0;
            }
            while (k-- > 0)
                rrr(a,b);
            while ((best_moves->to_a)-- > 0)
                rra(a);
            while ((best_moves->to_b)-- > 0)
                rrb(b); 
        }
        else
        {
            k = 0;
            while(k < absolute(best_moves->to_b))
            {
                if (best_moves->to_b > 0)
                    rb(b);
                else
                    rrb(b);
                k++;
            }
            k = 0;
            while(k < absolute(best_moves->to_a))
            {
                if (best_moves->to_a > 0)
                    ra(a);
                else
                    rra(a);
                k++;
            }
        }
        pa(a, b);

        // printf("------------after--------------\n");
        // print_stack(a, 'a');
        // print_stack(b, 'b');
        
    }

    int min_index = find_min(a);
    int min_a = a->stack[min_index];
    while(a->stack[0] != min_a)
    {
        if (min_index >= a->size / 2)
            ra(a);
        else
            rra(a);
    }
    // print_stack(a, 'a');
    // print_stack(b, 'b');
    // printf("min = %d\n", min_a);
   // printf("best elm: %d\n", b->stack[best_moves->index]);

}