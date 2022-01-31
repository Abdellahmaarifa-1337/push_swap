#include "../push_swap.h"
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
