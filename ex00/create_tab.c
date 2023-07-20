/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:46:43 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/20 15:22:34 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototype.h"

int	**create_tab(void)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * 6);
	if (!tab)
	{
		free(tab);
		return (tab);
	}
	while (i < 6)
	{
		tab[i] = malloc(sizeof(int) * 6);
		if (!tab[i])
		{
			free_tab(tab, i);
			return (0);
		}
		i++;
	}
	return (tab);
}

void	free_tab(int **tab, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

int	check_val(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	fill_tab(int **tab)
{
	int	i;
	int	j;

	j = 0;
	while (j < 6)
	{
		i = 0;
		while (i < 6)
		{
			tab[i][j] = 0;
			i++;
		}
		j++;
	}
}

void	fill_tab_param(int **tab, char *str)
{
	tab[0][1] = str[0] - '0';
	tab[0][2] = str[2] - '0';
	tab[0][3] = str[4] - '0';
	tab[0][4] = str[6] - '0';
	tab[1][0] = str[16] - '0';
	tab[2][0] = str[18] - '0';
	tab[3][0] = str[20] - '0';
	tab[4][0] = str[22] - '0';
	tab[1][5] = str[24] - '0';
	tab[2][5] = str[26] - '0';
	tab[3][5] = str[28] - '0';
	tab[4][5] = str[30] - '0';
	tab[5][1] = str[8] - '0';
	tab[5][2] = str[10] - '0';
	tab[5][3] = str[12] - '0';
	tab[5][4] = str[14] - '0';
}
