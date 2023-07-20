/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:04:22 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/15 18:20:55 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prototype.h"

int	main(int argc, char *argv[])
{
	int	**tab;

	if (argc != 2)
	{
		error();
		return (0);
	}
	tab = create_tab();
	if (!tab)
	{
		error();
		return (0);
	}
	if (!check_val(argv[1]))
	{
		free_tab(tab, 5);
		error();
		return (0);
	}
	fill_tab(tab);
	fill_tab_param(tab, argv[1]);
	if (!place_number(tab, 1, 1))
		error();
	free_tab(tab, 5);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	error(void)
{
	write(1, "Error\n", 6);
}
