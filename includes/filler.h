/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:39:15 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 20:37:36 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_plateau
{
	int		X;
	int		Y;
	char	**plateau;
}				t_plateau;

typedef struct	s_piece
{
	int		X;
	int		Y;
	char	**piece;
}				t_piece;

typedef struct	s_current
{
	int			player;
	char		mysign;
	t_piece		*piece;
	t_plateau	*plateau;
}				t_current;

int		init_struct(t_current *current);
void	first_lecture(t_current *current);
void	lecture(t_current *current);
void	fill_plateau(t_current *current, char **tab);
void	get_piece(t_current *current);

int		can_place_piece(t_current *current, int x, int yi, char c);
void	resolution(t_current *current);

#endif
