/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@41.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1016/03/19 11:30:11 by pabril            #+#    #+#             */
/*   Updated: 2016/03/19 11:40:17 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	eb_test(t_current *d)
{
	eb_print_info(d);
	eb_print_board(d);
	eb_print_piece(d);
}

void	eb_print_info(t_current *d)
{
	ft_putstr_fd("player : ", 1);
	ft_putchar_fd(d->mysign, 1);
	ft_putstr_fd(", board [", 1);
	ft_putnbr_fd(d->plateau->Y, 1);
	ft_putstr_fd(",", 1);
	ft_putnbr_fd(d->plateau->X, 1);
	ft_putstr_fd("], piece [", 1);
	ft_putnbr_fd(d->piece->Y, 1);
	ft_putstr_fd(",", 1);
	ft_putnbr_fd(d->piece->X, 1);
	ft_putstr_fd("]\n", 1);
}

void	eb_print_board(t_current *d)
{
	int x;
	int y;

	y = 0;
	ft_putstr_fd("map :\n", 1);
	while (y < d->plateau->Y)
	{
		x = 0;
		while (x < d->plateau->X)
		{
			ft_putchar_fd(d->plateau->plateau[y][x], 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

void	eb_print_piece(t_current *d)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_putstr_fd("piece :\n", 1);
	y = 0;
	while (y < d->piece->Y)
	{
		x = 0;
		while (x < d->piece->X)
		{
			ft_putchar_fd(d->piece->piece[y][x], 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}
