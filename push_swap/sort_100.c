#include "push_swap.h"
#include <unistd.h>
int find_max(int *arr, int size, int max);
void puch_min_max(stack *a, stack *b, int max);
void sort_three(stack *a, stack *b);
void sort_five(stack *a, stack *b);
int is_there_less_then(stack *a, int q)
{
	int res = 0;
	int i = 0;
	while(i < a->size)
	{
		if (a->stack[i] <= q)
			res = 1;
		i++;
	}
	return res;
}
int is_there_more_then_a(stack *a, int q)
{
	int res = 0;
	int i = 0;
	while(i < a->size)
	{
		if (a->stack[i] > q)
			res = 1;
		i++;
	}
	return res;
}
// void push_less(stack *a, stack *b, int q)
// {

// 	if (a->stack[a->size - 1] < q)
// 	{
// 		rotate_stack(a, b, "rra");
// 	}
// 	else{
// 		while(a->stack[0] > q )
// 		{
// 			rotate_stack(a,b,"ra");
// 		}
// 	}
// 	push_stack(a, b, "pb");
// }
void push_less(stack *a, stack *b, int q)
{
    int i = 0;
    while (a->stack[i] > q)
        i++;
    int j = 0;
    int size = a->size;
    while(a->stack[size - 1 -j] > q)
        j++;
    if (j < i)
    {
        //rra
        while(a->stack[0] > q)
            rotate_stack(a, b, "rra");
    }
    else
    {
        //ra
         while(a->stack[0] > q)
            rotate_stack(a, b, "ra");
    }
 	push_stack(a, b, "pb");
}
void push_more_a(stack *a, stack *b, int q)
{
    int i = 0;
    while (a->stack[i] <= q)
        i++;
    int j = 0;
    int size = a->size;
    while(a->stack[size - 1 -j] <= q)
        j++;
    if (j < i)
    {
        //rra
        while(a->stack[0] <= q)
            rotate_stack(a, b, "rra");
    }
    else
    {
        //ra
         while(a->stack[0] <= q)
            rotate_stack(a, b, "ra");
    }
 	push_stack(a, b, "pb");
}
void push_less_b(stack *a, stack *b, int q)
{
   int i = 0;
    while (b->stack[i] > q)
        i++;
    int j = 0;
    int size = b->size;
    while(b->stack[size - 1 -j] > q)
        j++;
    if (j < i)
    {
        //rra
        while(b->stack[0] > q)
            rotate_stack(a, b, "rrb");
    }
    else
    {
        //ra
         while(b->stack[0] > q)
            rotate_stack(a, b, "rb");
    }
 	push_stack(a, b, "pa");
}
int *copy_sorted(stack *a)
{
	int *arr;
	int i= 0;

	arr = (int *)malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
	int j;
	int temp;
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while(j < a->size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1]= arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}

	return arr;
}
int *copy_sorted_rev(stack *a)
{
	int *arr;
	int i= 0;

	arr = (int *)malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		arr[i] = a->stack[i];
		i++;
	}
	int j;
	int temp;
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while(j < a->size - i - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1]= arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}

	return arr;
}
void sort_four(stack *a, stack *b)
{
}


void puch_min_max_a(stack *a, stack *b, int max)
{
	int i_max;
	i_max = find_max(a->stack, a->size, max);
	//printf("i_max = %d\n", i_max);
	int j = a->stack[i_max];
	if (j == a->stack[1])
	{
		swap_stack(a,b,"sa");
		push_stack(a,b,"pb");
		return ;
	}	
	if (i_max <= (a->size / 2))
	{
		while(a->stack[0] != j)
		{
				rotate_stack(a, b, "ra");
		}
	}
	else
	{	
		while(a->stack[0] != j)
		{
				rotate_stack(a, b, "rra");
		}
	}
	push_stack(a, b, "pb");

}
void print_stack(stack *a, char stack);
int find_elm(int *arr, int size, int n)
{
    int i = 0;
    while(i < size)
    {
        if(arr[i] == n)
            return i;
        i++;
    }
    return 0;
}
void sort_big(stack *a, stack *b);
void sort_500(stack *a, stack *b)
{
	// int j;
	// if(b->size == 2 && b->stack[0] < b->stack[1])
	// 	swap_stack(a, b, "sb");
	// while(b->size)
	// 	push_stack(a, b, "pa");
	int q;
	int i = 1;
    int *arr;
    int x;
    int j = 0;
    arr = copy_sorted_rev(a);
    int size_a = a->size;
	while (i < 4)
	{
		q = arr[(size_a*i / 4) - 1];
        // printf("%d",(size_a * i)/4 + 7);
		if(is_there_less_then(a, q))
        {
			push_less(a, b, q);
        }
          i++;
	}

    while(b->size)
    {
        push_stack(a,b,"pa");
    }
    // //      
    sort_big(a, b);
    // i = 1;
    // arr = copy_sorted(a);
    // size_a = a->size;
	// while (i <= 25)
	// {
    //     //9,13
	// 	q = arr[((size_a * i) / 25)  - 1];
    //     // printf("%d",(size_a * i)/4 + 7);
	// 	while(is_there_less_then(a, q))
	// 		push_less(a, b, q);
    //      if(b->stack[0] < b->stack[1])
    //          swap_stack(a, b, "sb");
	// 	  i++;
	// }
    // i = 0;
    // while (i++ < 50)
    // {
    //     //rotate_stack(a, b, "rrb");
    //     push_stack(a, b, "pa");    
    // }
    // i = 1;
    //  j = 0;
    // size_a = a->size;
    // arr = copy_sorted(b);
    // while (i <= 25 ) 
	// {
    //     //9,13
	// 	q = arr[((size_a * i) / 25) - 1];
    //     // printf("%d",(size_a * i)/4 + 7);
	// 	while(is_there_less_then(a, q))
	// 		push_less_b(a, b, q);
    //     if(b->stack[0] < b->stack[1])
    //         swap_stack(a, b, "sb");
    //     //printf("check %d\n", j);

	// 	i++;
	// }

    	//   puch_min_max_a(a, b, 0);
        //   sort_three(a, b);
        // push_stack(a, b, "pb");
        // push_stack(a, b, "pb");
        // push_stack(a, b, "pb");

    // int dd = a->size;
    // i = 1;
    //  j = 0;
    // int size_b = b->size;
    // arr = copy_sorted_rev(b);
    // while (i <= 50 ) 
	// {
    //     //9,13
	// 	q = arr[((size_b * i) / 50) - 1];
    //     // printf("%d",(size_a * i)/4 + 7);
	// 	while(is_there_less_then(b, q))
	// 		push_less_b(a, b, q);
    //     if(a->stack[0] < a->stack[1])
    //         swap_stack(a, b, "sa");
    //     //printf("check %d\n", j);

	// 	i++;
	// }
    // i = 0;
    // while(i++ < 4)
    //     rotate_stack(a, b, "rra");
//print_stack(b, 'b');
//printf("j == %d\n", j);
// printf("left: %d\n", dd);
    // if(b->stack[0] > b->stack[1])
    //     swap_stack(a,b,"sb");
    // push_stack(a, b, "pa");
    //     push_stack(a, b, "pa");
    // printf("size a :%d\n", a->size);
    // int r = a->size - 3;
    // // printf("size of a lewla %d\n", a->size);
    // while (a->size > 3)
    // {
    //     int min_a = a->stack[find_max(a->stack, a->size, 0)];
    //     int p = find_max(a->stack, a->size, 0);
    //     // printf("%d\n",min_a);
    //     // printf("%d\n",p);
    //     // printf("%d\n",a->stack[0]);
    //     //sleep(3);
    //     //printf("1\n");
    //     //sleep(1);
    //     while(a->stack[0] != min_a)
    //     {
    //         if ((a->size)/2 <= p)
    //         {   
    //         rotate_stack(a, b, "rra");
    //         }
    //         else
    //         {
    //             rotate_stack(a,b,"ra");
    //         } 
    //         // rotate_stack(a,b,"ra");
    //         // printf("3tini : %d",a->stack[0]);
    
    //     }

    //     push_stack(a, b, "pb");
    //     // printf("size of a : %d\n",a->size);
    //     //sleep(1);
    // }   
    
    // sort_three(a,b);
    // int d = 0;
    // while(d < r )
    // {
    //     push_stack(a, b, "pa");
    //     d++;
    // // // }
	// i = 0;
	// int size = a->size;
	// while(i < size)
	// {
	// 	puch_min_max(a, b, 1);
	// 	i++;
	// }
    //     sort_big(a, b);

    //  print_stack(a, 'a');

    //  print_stack(b, 'b');

}