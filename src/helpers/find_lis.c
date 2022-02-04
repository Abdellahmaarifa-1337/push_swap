/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:13:43 by amaarifa          #+#    #+#             */
/*   Updated: 2022/02/04 20:35:33 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
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
*/
/*
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
*/
void	append_to_lis(t_lis *lis_list, int elm)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * (lis_list->size + 1));
	while (i < lis_list->size)
	{
		new_arr[i] = lis_list->arr[i];
		i++;
	}
	new_arr[i] = elm;
	free(lis_list->arr);
	lis_list->arr = new_arr;
	lis_list->size += 1;
}

t_lis	*copy_lis(t_lis *lis_list)
{
	t_lis	*temp;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * lis_list->size);
	temp = (t_lis *)malloc(sizeof(t_lis));
	i = 0;
	while (i < lis_list->size)
	{
		arr[i] = lis_list->arr[i];
		i++;
	}
	temp->arr = arr;
	temp->size = lis_list->size;
	return (temp);
}

t_lis	**init_lises(int *arr, int size)
{
	t_lis	**all_lis;
	int		n;
	t_lis	*init_lis;

	n = 0;
	all_lis = (t_lis **)malloc(sizeof(t_lis *) * size);
	while (n < size)
	{
		init_lis = (t_lis *)malloc(sizeof(t_lis));
		init_lis->arr = (int *)malloc(sizeof(int) * 1);
		init_lis->arr[0] = 0;
		init_lis->size = 0;
		all_lis[n] = init_lis;
		n++;
	}
	append_to_lis(all_lis[0], arr[0]);
	return (all_lis);
}

t_lis	*get_perfect_lis(t_lis **all_lis, int size)
{
	t_lis	*temp;
	int		i;

	temp = copy_lis(all_lis[0]);
	i = 1;
	while (i < size)
	{
		if (all_lis[i]->size > temp->size)
		{
			free(temp->arr);
			free(temp);
			temp = copy_lis(all_lis[i]);
		}
		free(all_lis[i]->arr);
		free(all_lis[i]);
		i++;
	}
	return (temp);
}

t_lis	*find_lis(int *arr, int size)
{
	t_lis	**all_lis;
	t_lis	*perfect_lis;
	int		j;
	int		i;

	all_lis = init_lises(arr, size);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && all_lis[i]->size < all_lis[j]->size + 1)
			{
				free(all_lis[i]->arr);
				free(all_lis[i]);
				all_lis[i] = copy_lis(all_lis[j]);
			}
			j++;
		}
		append_to_lis(all_lis[i], arr[i]);
		i++;
	}
	perfect_lis = get_perfect_lis(all_lis, size);
	return (perfect_lis);
}
