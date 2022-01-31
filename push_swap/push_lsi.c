
#include <stdio.h>
#include "push_swap.h"

int calc_LIS(int *arr, int index, int size)
{
    int i = 1;
    int temp = index;
    while(index < size)
    {
        if (arr[temp] < arr[index])
        {
            temp = index;
            i++;
        }    
        index++;
    }
    return i;
}
int *get_LIS(int *arr, int LIS_index, int LIS_size, int size)
{
    int *LIS;
    
    LIS = malloc(sizeof(int) * LIS_size);
    LIS[0] = arr[LIS_index];
    int i = 1;
    int temp = LIS_index;
    while(LIS_index < size)
    {
        if (arr[temp] < arr[LIS_index])
        {
            temp = LIS_index;
            LIS[i] = arr[LIS_index];
            i++;
        }    
        LIS_index++;
    }
    return LIS;
}

void append_to_lis(lis *lis_list, int elm)
{
    int *new_arr = (int *)malloc(sizeof(int) * (lis_list->size + 1));
    int i = 0;
    while(i < lis_list->size)
    {
        new_arr[i] = lis_list->arr[i];
        i++;
    }
    new_arr[i] = elm;
    free(lis_list->arr);
    lis_list->arr = new_arr;
    lis_list->size += 1;
}
lis *copy_lis(lis *lis_list)
{
    lis *temp;
    temp = (lis *)malloc(sizeof(lis));
    int *arr = (int *)malloc(sizeof(int) * lis_list->size);
    int i = 0;
    while(i < lis_list->size)
    {
        arr[i] = lis_list->arr[i];
        i++;
    }
    temp->arr = arr;
    temp->size = lis_list->size;
    return temp;
}
lis *find_LIS(int *arr, int size)
{


    lis **all_lis;
    all_lis = (lis **)malloc(sizeof(lis *) * size);
    int n = 0;
    while(n < size)
    {
        lis *init_lis;
        init_lis = (lis *)malloc(sizeof(lis));
        init_lis->arr = (int *)malloc(sizeof(int) * 1);
        init_lis->arr[0] = 0;
        init_lis->size = 0;
        all_lis[n] = init_lis;
        n++;
    }
    append_to_lis(all_lis[0], arr[0]);
    int i = 1;
    int j;
    while(i < size)
    {
        j = 0;
        while (j < i)
        {
            if(arr[i] > arr[j] && all_lis[i]->size < all_lis[j]->size + 1)
                all_lis[i] = copy_lis(all_lis[j]);
            j++;
        }
        append_to_lis(all_lis[i], arr[i]);
        i++;
    }
    lis *temp;
    temp = copy_lis(all_lis[0]);
    i = 1;
    while(i < size)
    {
        if(all_lis[i]->size > temp->size)
        {
            free(temp->arr);
            temp = copy_lis(all_lis[i]);
        }
        free(all_lis[i]->arr);
        i++;
    }

    return temp;
}

stack *copy_stack(stack *a)
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    int *temp_arr;
    temp_arr = (int *)malloc(sizeof(int) * a->size);
    int i = 0;
    while(i < a->size)
    {
        temp_arr[i] = a->stack[i];
        i++;
    }
    temp->stack = temp_arr;
    temp->size = a->size;
}
int is_in_lis(lis *lis_arr, int n)
{
    int i = 0;
    while(i < lis_arr->size)
    {
        if(n == lis_arr->arr[i])
            return 1;
        i++;
    }
    return 0;
}


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
void sort_arr(int *arr, int size)
{
    int j;
	int temp;
	int i = 0;
	while (i < size)
	{
		j = 0;
		while(j < size - i - 1)
		{
			if ((arr)[j] > (arr)[j + 1])
			{
				temp = (arr)[j + 1];
				(arr)[j + 1]= (arr)[j];
				(arr)[j] = temp;
			}
			j++;
		}
		i++;
	}
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
int find_min(stack *a)
{
    int *arr;
    arr = (int *)malloc(sizeof(int) * a->size);
    int i = 0;
    while(i < a->size)
    {
        arr[i] = a->stack[i];
        i++;
    }
    sort_arr(arr, a->size);
    i = 0;
    while(i < a->size)
    {
        if(a->stack[i] == arr[0])
            break;
        i++;
    }
    return i;
}

void sort_big(stack *a, stack *b)
{
    stack *temp;
    temp = copy_stack(a);
    int min_temp = find_max(temp->stack, temp->size, 0);
    int min = temp->stack[min_temp];
    while (temp->stack[0] != min)
    {
        if (min_temp <= temp->size / 2)
            rotate_stack(temp, b, "rt");
        else
            rotate_stack(temp, b, "rrt");
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
            rotate_stack(a, b, "ra");
        push_stack(a, b, "pb");
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
                rotate_stack(a, b, "rr");
            while ((best_moves->to_a)-- > 0)
                rotate_stack(a, b, "ra");
            while ((best_moves->to_b)-- > 0)
                rotate_stack(a, b, "rb");   
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
                rotate_stack(a, b, "rrr");
            while ((best_moves->to_a)-- > 0)
                rotate_stack(a, b, "rra");
            while ((best_moves->to_b)-- > 0)
                rotate_stack(a, b, "rrb");   
        }
        else
        {
            k = 0;
            while(k < absolute(best_moves->to_b))
            {
                if (best_moves->to_b > 0)
                    rotate_stack(a, b, "rb");
                else
                    rotate_stack(a, b, "rrb");
                k++;
            }
            k = 0;
            while(k < absolute(best_moves->to_a))
            {
                if (best_moves->to_a > 0)
                    rotate_stack(a, b, "ra");
                else
                    rotate_stack(a, b, "rra");
                k++;
            }
        }
        push_stack(a, b, "pa");

        // printf("------------after--------------\n");
        // print_stack(a, 'a');
        // print_stack(b, 'b');
        
    }

    int min_index = find_min(a);
    int min_a = a->stack[min_index];
    while(a->stack[0] != min_a)
    {
        if (min_index >= a->size / 2)
            rotate_stack(a, b, "ra");
        else
            rotate_stack(a, b, "rra");
    }
    // print_stack(a, 'a');
    // print_stack(b, 'b');
    // printf("min = %d\n", min_a);
   // printf("best elm: %d\n", b->stack[best_moves->index]);

}