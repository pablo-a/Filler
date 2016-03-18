/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:39:15 by pabril            #+#    #+#             */
/*   Updated: 2016/03/18 11:36:40 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

typedef struct	s_plateau
{
	int X;
}				t_plateau;

typedef struct	s_piece
{
	char *piece;
}				t_piece;

typedef struct	s_current
{
	int			player;
	t_piece		piece;
	t_plateau	plateau;
}				t_current;

void	first_lecture(t_current *current);
int		lecture(t_current *current);
int		resolution(t_current *current);

#endif
