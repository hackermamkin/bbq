/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:56:16 by djeanna           #+#    #+#             */
/*   Updated: 2019/03/20 20:41:48 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		bsq(char *file, int check)
{
	char	*buf;
	int		str_len;
	int		first_str_len;

	if (check)
		buf = reading_file(file);
	else
		buf = reading_from_input();
	if (buf == NULL)
	{
		error();
		return (0);
	}
	if (!is_valid(buf, &str_len, &first_str_len))
	{
		error();
		return (0);
	}
	find_square(buf, str_len, first_str_len);
	free(buf);
	return (1);
}
