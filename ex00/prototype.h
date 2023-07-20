/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:47:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/07/15 18:18:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROTOTYPE_H
# define PROTOTYPE_H
# include <stdlib.h>
# include <unistd.h>

int		place_number(int **tab, int i, int j);
int		check_if_number_is_valid(int **tab, int k, int i, int j);
int		check_final_tab_row(int **tab, int j, int i);
int		check_final_tab_col(int **tab, int i, int j);
int		**create_tab(void);
int		check_val(char *str);
void	fill_tab(int **tab);
void	error(void);
void	fill_tab_param(int **tab, char *str);
void	print_tab(int **tab);
void	ft_putchar(char c);
void	free_tab(int **tab, int i);

#endif
