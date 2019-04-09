/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:38:12 by djeanna           #+#    #+#             */
/*   Updated: 2019/03/20 20:16:49 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int iter;
	int res;
	int sign;

	sign = 1;
	res = 0;
	iter = 0;
	while (str[iter] == ' ' || str[iter] == '\n' || str[iter] == '\t' ||
			str[iter] == '\f' || str[iter] == '\r' || str[iter] == '\v')
		iter++;
	if (str[iter] == '-')
	{
		sign = -1;
		iter++;
	}
	else if (str[iter] == '+')
		iter++;
	while ('0' <= str[iter] && str[iter] <= '9')
	{
		res = 10 * res + (str[iter] - '0');
		iter++;
	}
	return (sign * res);
}
