/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_algoritm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:51 by gfreddie          #+#    #+#             */
/*   Updated: 2019/03/20 20:36:06 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		snake_algoritm(int index, int size, char *str)
{
	int k;
	int j;
	int fix_ind;
	int step;

	j = index;
	fix_ind = index;
	k = index;
	step = 0;
	while (check_func(str[index]) && check_func(str[j]) && str[fix_ind] != '\n'
	&& (j % size) >= k % size && (index / size) >= (k / size))
	{
		if (j % size == k % size && ++step)
		{
			index = fix_ind + size + 1;
			j = index;
			fix_ind = index;
		}
		if (j % size > k % size && index / size > k / size
		&& check_func(str[index]) && str[fix_ind] != '\n' && --j)
			index -= size;
		else
			break ;
	}
	return (step);
}

int		check_func(char s)
{
	return (s == g_empty_symbol);
}

void	print_arr(char *arr)
{
	while (*arr)
		write(1, arr++, 1);
}

void	fill(char *arr, int sq, int ind, int size)
{
	int iter;
	int iter2;

	iter = 0;
	iter2 = 0;
	while (iter < sq)
	{
		iter2 = 0;
		while (iter2 < sq)
		{
			arr[ind + iter2++] = g_full_symbol;
		}
		ind += size;
		iter++;
	}
}

void	find_square(char *arr, int size, int first_str_len)
{
	int max_sq;
	int max_ind;
	int temp;
	int i;

	temp = 0;
	i = 0;
	max_ind = 0;
	max_sq = 0;
	while (arr[i])
	{
		temp = snake_algoritm(i, size, arr + first_str_len);
		if (temp == size)
			break ;
		if (temp > max_sq)
		{
			max_sq = temp;
			max_ind = i;
		}
		i++;
	}
	fill(arr + first_str_len, max_sq, max_ind, size);
	print_arr(arr + first_str_len + 1);
}
