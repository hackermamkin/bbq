/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:16:21 by djeanna           #+#    #+#             */
/*   Updated: 2019/03/20 20:17:33 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char	*reading_file(char *file);
int		bsq(char *file, int check);
int		ft_atoi(char *str);
void	error(void);
int		is_symbol_valid(char *buf, int first_len, int iter);
int		is_num_of_str_and_symbols_valid(char *buf, int num_of_str,
int		*first_str_len, int *str_len);
int		is_valid(char *buf, int *str_len, int *first_str_len);
void	find_square(char *arr, int size, int first_str_len);
void	fill(char *arr, int sq, int ind, int size);
void	print_arr(char *arr);
int		check_func(char s);
int		snake_algoritm(int index, int size, char *str);
char	*reading_file(char *file);
char	*funny_copy(char *dest, char buf, int size);
char	*reading_from_input(void);

char	g_empty_symbol;
char	g_obstacle_symbol;
char	g_full_symbol;

#endif
