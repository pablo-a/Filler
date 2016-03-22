/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:40:29 by pabril            #+#    #+#             */
/*   Updated: 2016/03/22 11:15:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define PLATEAU current->plateau->plateau
#define PIECE current->piece->piece
#define X x
#define Y y

void	fill_plateau(t_current *current, char **line, int *tab)
{
	if (tab[1] == 0)
	{
		current->plateau->Y = ft_atoi(line[1]);
		current->plateau->X = ft_atoi(line[2]);
		if ((PLATEAU = (char **)malloc(sizeof(char *) *
						(current->plateau->Y + 1))) == 0)
			perror("wasnt able to allocate memory for the gameboard");
		PLATEAU[current->plateau->Y] = "\0";
	}
	if (tab[1] > 1)
		PLATEAU[tab[1] - 2] = ft_strdup(line[1]);
	tab[1]++;
}

void	lecture(t_current *current, int *tab)
{
	char	*str;
	char	**line;

	while (get_next_line(0, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		if (ft_strcmp(line[0], "$$$") == 0 && tab[0] == 0)
		{
			current->player = ft_atoi(&line[2][1]);
			if (current->player == 1)
				current->mysign = 'o';
			else
				current->mysign = 'x';
			tab[0]++;
		}
		else if (ft_strcmp(line[0], "Plateau") == 0 ||
				tab[1] < current->plateau->Y + 2)
			fill_plateau(current, line, tab);
		else if (ft_strcmp(line[0], "Piece") == 0 ||
				tab[2] < current->piece->Y + 1)
			get_piece(current, line, tab);
	}
}

void	get_piece(t_current *current, char **line, int *tab)
{
	if (tab[2] == 0)
	{
		current->piece->Y = ft_atoi(line[1]);
		current->piece->X = ft_atoi(line[2]);
		if ((PIECE = (char **)malloc(sizeof(char *) *
						(current->piece->Y + 1))) == 0)
			perror("wasnt able to allocate memory for the piece");
		PIECE[current->piece->Y] = "\0";
	}
	else if (tab[2])
		PIECE[tab[2] - 1] = ft_strdup(line[0]);
	tab[2]++;
	if (tab[2] == current->piece->Y + 1)
	{
		resolution(current);
		init_struct(current, tab);
	}
}

void	init_struct(t_current *current, int *tab)
{
	if (!current->piece)
		if ((current->piece = (t_piece *)malloc(sizeof(t_piece))) == 0)
			return (perror("bad allocation"));
	if (!current->plateau)
		if ((current->plateau = (t_plateau *)malloc(sizeof(t_plateau))) == 0)
			return (perror("bad allocation"));
	current->player = 0;
	current->piece->X = 0;
	current->piece->Y = 0;
	current->plateau->X = 0;
	current->plateau->Y = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
}

int		free_tab_str(char **str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	return (0);
}
