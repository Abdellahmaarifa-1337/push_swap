#include "push_swap.h"


int find_max(int *arr, int size, int max)
{
	int k = 0;
	int i = 0;
	int j;
	while (k < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[j] > arr[i] && max)
				i = j;
			if (arr[j] < arr[i] && !max)
				i = j;
			j++;
		}
		k++;
	}
	return i;
}
int is_sorted(int *arr, int size)
{
	int i = 0;
	while(i < size - 1)
	{
		if(arr[i] > arr[i + 1])
		{
			i++;
			continue;
		}
		break;
	}
	if (i == size - 1)
		return 1;
	return 0;
}
void sort_three(stack *a, stack *b)
{
	int i = find_max(a->stack, a->size, 1);
	if (i == 0)
	{
		rotate_stack(a, b, "ra");
		if (a->stack[0] > a->stack[1])
			swap_stack(a, b, "sa");
	}
	else if (i == 1 && a->stack[2] < a->stack[0])
		rotate_stack(a, b, "rra");
	else if (i == 1)
	{
		swap_stack(a, b, "sa");
		rotate_stack(a, b, "ra");
	}
	else if (a->stack[0] > a->stack[1])
		swap_stack(a, b, "sa");
	//printf("index is %d\n", i);
}

void puch_min_max(stack *a, stack *b, int max)
{
	int i_max;
	i_max = find_max(b->stack, b->size, max);
	//printf("i_max = %d\n", i_max);
	int j = b->stack[i_max];
	if (j == b->stack[1])
	{
		swap_stack(a,b,"sb");
		push_stack(a,b,"pa");
		return ;
	}	
	if (i_max <= (b->size / 2))
	{
		while(b->stack[0] != j)
		{
				rotate_stack(a, b, "rb");
		}
	}
	else
	{	
		while(b->stack[0] != j)
		{
				rotate_stack(a, b, "rrb");
		}
	}
	push_stack(a, b, "pa");

}
void sort_five(stack *a, stack *b)
{
	puch_min_max(a, b, 0);
	puch_min_max(a, b, 0);
	sort_three(a, b);
	push_stack(a, b, "pa");
	push_stack(a, b, "pa");
}
/*
int quarter_point(stack *a, int quarter)
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

	return arr[((a->size * quarter) / 4) - 1];
}*/
void print_stack(stack *a, char stack);
/*
void push_less(stack *a, stack *b, int q)
{

	// int hold_first = 0;
	// while(hold_first  <= a->size / 2)
	// {
	// 	if (a->stack[hold_first] <= q)
	// 		break;
	// 	hold_first++;
	// }
	// int hold_second = a->size - 1;
	// while(hold_second > a->size / 2)
	// {
	// 	if (a->stack[hold_second] < q)
	// 		break;
	// 	hold_second--;
	// }
	// int j = 0;
	// //printf("q == %d hold first = %d and hold second = %d\n",q, hold_first, (a->size - hold_second));
	// //print_stack(a, 'a');

	// if (hold_first <= (a->size - hold_second))
	// {
	// 	while(j++ < hold_first)
	// 		rotate_stack(a, b, "ra");
	// }
	// else
	// {
	// 	while(j++ < (a->size - hold_second))
	// 		rotate_stack(a, b, "rra");		
	// }

	// push_stack(a, b, "pb");


	if (a->stack[a->size - 1] < q)
	{
		rotate_stack(a, b, "rra");
	}
	else{
		while(a->stack[0] > q )
		{
			rotate_stack(a,b,"ra");
		}
	}
	push_stack(a, b, "pb");
	// int j = 0;
	// int max = 0;
	// int min = 0;
	// while(j < b->size)
	// {
	// 	if(a->stack[0] > b->stack[j])
	// 		max++;
	// 	if(a->stack[0] < b->stack[j])
	// 		min++;
	// 	j++;
	// }
	// int d = 0;
	// if (max == b->size)
	// 	push_stack(a, b, "pb");
	// else if (min == b->size)
	// {
	// 	push_stack(a, b, "pb");
	// 	rotate_stack(a, b, "rb");
	// }
	// else{
	// 	while(a->stack[0] < b->stack[0])
	// 	{
	// 		rotate_stack(a, b, "rb");
	// 		d++;
	// 	}
	// 	push_stack(a, b, "pb");
	// 	while(d > 0)
	// 	{
	// 		rotate_stack(a, b, "rrb");
	// 		d--;
	// 	}
	// 	// int min_i = b->stack[find_max(b->stack, b->size, 1)];
	// 	// while(b->stack[0] != min_i)
	// 	// 	rotate_stack(a, b, "rb");
	// 	// push_stack(a, b, "pb");
	// }
}*/
/*
int is_there_less_then(stack *a, int q)
{
	int res = 0;
	int i = 0;
	while(i < a->size)
	{
		if (a->stack[i] < q)
			res = 1;
		i++;
	}
	return res;
}
*/
/*
int med_point(int *a, int s)
{
	int arr[s];
	int i= 0;
	//printf("s === %d\n", s);
	while (i <= s)
	{
		arr[i] = a[i];
		i++;
	}
	int j;
	int temp;
	i = 0;
	while (i < s)
	{
		j = 0;
		while(j < s - i - 1)
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
	return arr[s / 2];
}
int *chunk_arr(stack *a, int size)
{
	int *arr;
	arr = (int *)malloc(sizeof(int) * size);
	int i = 0;
	while (i < size)
	{
		arr[i] = a->stack[i];
		i++;
	}
	return arr;
}

int is_there_more_then(stack *b, int m, int chunk_size)
{
	int res = 0;
	int i = 0;
	while(i < chunk_size && b->size)
	{
		if (b->stack[i] > m)
			res = 1;
		i++;
	}
	return res;
}
int push_more(stack *a, stack *b, int m, int chunk_size)
{
	int max_in_chunk = find_max(b->stack, chunk_size, 1);
	int max = b->stack[max_in_chunk];
	int j = 0;
	while (b->stack[0] != max)
	{
		rotate_stack(a, b, "rb");
		j++;
	}
	push_stack(a , b, "ra");
	return j;
}
void push_less(stack *a, stack *b, int q);
int is_there_less_then(stack *a, int q);

void sort_one_handred(stack *a, stack *b)
{
	int m;
	int *chunks;
	chunks = (int *)malloc(sizeof(int) * a->size);
	int i = 0;
	int chunk_size;
	while(a->size > 2)
	{
		chunk_size = 0;
		m = med_point(a->stack, a->size);
		while(is_there_less_then(a, m) == 1)
		{
			push_less(a, b, m);
			chunk_size++;
		}
		chunks[i] = chunk_size;
		i++;
	}
	chunks[i] = 0;
	if(a->size == 2 && a->stack[0] > a->stack[1])
		swap_stack(a, b, "sa");

	int k = i - 1;
	int j;
	while(k >= 0)
	{
		if (chunks[k] > 2)
		{
			if (is_sorted(chunk_arr(b, chunks[k]), chunks[k]))
			{
				//push to a and go to next chunk
				while(chunks[k] > 0)
				{
					//printf("chunk sorted");
					push_stack(a, b, "pa");
					chunks[k] -= 1;
				}
				k--;
				continue;
			}
			while(chunks[k] > 2)
			{
				//printf("k == %d\n", chunks[k]);
				m = med_point(chunk_arr(b, chunks[k]), chunks[k]);
				if (is_there_more_then(b, m, chunks[k]))
				{
					j = push_more(a, b, m, chunks[k]);
					while(j > 0)
					{
						rotate_stack(a, b, "rrb");
						j--;
					}
				}
				 chunks[k] -= 1;
			}
			if(chunks[k] == 2)
			{
				if(b->stack[0] < b->stack[1])
					swap_stack(a, b, "sb");
			}
			while(chunks[k] > 0)
			{
				push_stack(a, b, "pa");
				chunks[k] -= 1;
			}
		}
		else
		{

			if (chunks[k] == 2 && b->stack[0] < b->stack[1])
				swap_stack(a, b, "sb");
			j = 0;
			while(chunks[k] > 0)
			{
				push_stack(a, b, "pa");
				chunks[k] -= 1;
			}
			
		}
		k--;
	}
	// int j;
	// if(b->size == 2 && b->stack[0] < b->stack[1])
	// 	swap_stack(a, b, "sb");
	// while(b->size)
	// 	push_stack(a, b, "pa");
	// int q;
	// int i = 1;
	// while (i <3 )
	// {
	// 	q = quarter_point(a, i);
	// 	while(is_there_less_then(a, q))
	// 		push_less(a, b, q);
	// 	// if (i != 3)
	// 	// {
	// 	// 	while (b->size != 0)
	// 	// 		push_stack(a,b,"pa");
	// 	// }

	// 	// if (i  == 1)
	// 	// {
	// 	// 	j = 0;
	// 	// 	int size = b->size;
	// 	// 	while(j < size)
	// 	// 	{
	// 	// 		puch_min_max(a, b, 1);
	// 	// 		j++;
	// 	// 	}
	// 	// }
	// 	  i++;
	// }

	// i = 0;
	// int size = b->size;
	// while(i < size)
	// {
	// 	puch_min_max(a, b, 1);
	// 	i++;
	// }


}*/

void sort_one_handred(stack *a, stack *b);
void sort_big(stack *a, stack *b);
void sort_500(stack *a, stack *b);

void sort_stack(stack *a, stack *b)
{
		//int *lis;
		//lis = get_lis(a);

		// this code should only work if the array not sorted!!
		if (a->size <= 3)
			sort_three(a, b);
		else if (a->size <= 5)
			sort_five(a, b);
		else if (a->size <= 100)
			sort_big(a, b);
		else if (a->size <= 500)
			sort_500(a, b);
		//print_lis(lis);
			
}