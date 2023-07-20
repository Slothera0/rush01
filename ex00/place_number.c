/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:13:20 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/16 14:12:21 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"

int	place_number(int **tab, int i, int j)
{
	int	k;

	if (i == 1 && j == 5 && check_final_tab_row(tab, 0, 1))
	{
		print_tab(tab);
		return (1);
	}
	k = 5;
	while (--k > 0)
	{
		if (check_if_number_is_valid(tab, k, i, j))
		{
			tab[i][j] = k;
			if (i < 4)
			{
				if (place_number(tab, i + 1, j) == 1)
					return (1);
			}
			else if (place_number(tab, 1, j + 1) == 1)
				return (1);
			tab[i][j] = 0;
		}
	}
	return (0);
}

int	check_if_number_is_valid(int **tab, int k, int i, int j)
{
	int	index;

	index = 1;
	while (index < 5)
	{
		if (tab[index][j] == k)
			return (0);
		if (tab[i][index] == k)
			return (0);
		index++;
	}
	return (1);
}

int	check_final_tab_row(int **tab, int j, int i)
{
	int	count[2];
	int	temp[2];

	while (++j < 5)
	{
		count[0] = 1;
		count[1] = 1;
		temp[1] = tab[4][j];
		temp[0] = tab[1][j];
		i = 1;
		while (++i < 5)
		{
			if (tab[i][j] > temp[0])
				count[0]++;
			if (tab[i][j] > temp[0])
				temp[0] = tab[i][j];
			if (tab[5 - i][j] > temp[1])
				count[1]++;
			if (tab[5 - i][j] > temp[1])
				temp[1] = tab[5 - i][j];
		}
		if (count[0] != tab[0][j] || count[1] != tab[5][j])
			return (0);
	}
	return (check_final_tab_col(tab, 0, 1));
}

int	check_final_tab_col(int **tab, int i, int j)
{
	int	count[2];
	int	temp[2];

	while (++i < 5)
	{
		count[0] = 1;
		count[1] = 1;
		temp[0] = tab[i][1];
		temp[1] = tab[i][4];
		j = 1;
		while (++j < 5)
		{
			if (tab[i][j] > temp[0])
				count[0]++;
			if (tab[i][j] > temp[0])
				temp[0] = tab[i][j];
			if (tab[i][5 - j] > temp[1])
				count[1]++;
			if (tab[i][5 - j] > temp[1])
				temp[1] = tab[i][5 - j];
		}
		if (count[0] != tab[i][0] || count[1] != tab[i][5])
			return (0);
	}
	return (1);
}

void	print_tab(int **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			ft_putchar(tab[i][j] + '0');
			if (j != 4)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
