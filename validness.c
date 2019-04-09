/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:23:06 by djeanna           #+#    #+#             */
/*   Updated: 2019/03/20 19:52:09 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_symbol_valid(char *buf, int first_len, int iter)
{
	return (buf[first_len + iter] == g_obstacle_symbol ||
			buf[first_len + iter] == g_empty_symbol ||
			buf[first_len + iter] == '\n');
}

int		is_num_of_str_and_symbols_valid(char *buf, int num_of_str,
	int *first_str_len, int *str_len)
{
	int iter;
	int str_num;
	int check;
	int cur_len;

	iter = 1;
	check = 1;
	cur_len = 0;
	str_num = 0;
	while (buf[*first_str_len + iter++])
	{
		cur_len++;
		if (!is_symbol_valid(buf, *first_str_len, iter - 1))
			return (0);
		if (buf[*first_str_len + iter - 1] == '\n')
		{
			str_num++;
			if (*str_len == 0)
				*str_len = cur_len;
			else if (*str_len != cur_len)
				return (0);
			cur_len = 0;
		}
	}
	return (str_num == num_of_str);
}

int		know_num_of_str(char *buf, int first_str_len)
{
	int num_of_str;

	if (buf[first_str_len - 3] == buf[first_str_len - 2] ||
			buf[first_str_len - 2] == buf[first_str_len - 1] ||
			buf[first_str_len - 3] == buf[first_str_len - 1])
		return (0);
	num_of_str = ft_atoi(buf);
	if (buf[first_str_len - 3] <= '9' && buf[first_str_len - 3] >= '0')
	{
		num_of_str /= 10;
		if (buf[first_str_len - 2] <= '9' && buf[first_str_len - 2] >= '0')
		{
			num_of_str /= 10;
			if (buf[first_str_len - 1] <= '9' && buf[first_str_len - 1] >= '0')
				num_of_str /= 10;
		}
	}
	return (num_of_str);
}

int		is_valid(char *buf, int *str_len, int *first_str_len)
{
	int num_of_str;
	int iter;

	iter = 0;
	*str_len = 0;
	*first_str_len = 0;
	while (buf[*first_str_len] && buf[*first_str_len] != '\n')
		(*first_str_len)++;
	if (*first_str_len < 4)
		return (0);
	num_of_str = know_num_of_str(buf, *first_str_len);
	g_empty_symbol = buf[*first_str_len - 3];
	g_full_symbol = buf[*first_str_len - 1];
	g_obstacle_symbol = buf[*first_str_len - 2];
	if (num_of_str <= 0)
		return (0);
	if (!is_num_of_str_and_symbols_valid(buf, num_of_str,
				first_str_len, str_len))
		return (0);
	return (1);
}
