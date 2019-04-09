/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:49:37 by djeanna           #+#    #+#             */
/*   Updated: 2019/03/20 20:44:26 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*reading_file(char *file)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;
	if (!(buf = malloc(sizeof(char))))
		return (NULL);
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1) == 1)
		i++;
	if (i == 0)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	if (!(buf = (char *)malloc(sizeof(char) * (i))))
		return (NULL);
	read(open(file, O_RDONLY), buf, i);
	buf[i] = '\0';
	close(fd);
	return (buf);
}

char	*funny_copy(char *dest, char buf, int size)
{
	char	*new;
	int		iter;

	iter = 0;
	if (!(new = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	while (iter < size && *dest)
	{
		new[iter] = dest[iter];
		iter++;
	}
	new[iter] = buf;
	new[iter + 1] = '\0';
	return (new);
}

char	*reading_from_input(void)
{
	int		i;
	char	*buf;
	char	temp;
	char	*temp_ptr;

	i = 0;
	buf = malloc(sizeof(char));
	while (read(0, &temp, 1) == 1)
	{
		temp_ptr = buf;
		buf = funny_copy(buf, temp, i);
		if (temp_ptr)
			free(temp_ptr);
		i++;
	}
	if (i == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
