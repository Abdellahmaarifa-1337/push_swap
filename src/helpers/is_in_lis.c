#include "../push_swap.h"

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
