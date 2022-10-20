/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:37:13 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 16:54:42 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	give_good_size(t_solong *d)
{
	int	size;

	size = ft_strlen(d->map[0]);
	if (d->size > size)
	{
		d->square_size = 1000 / d->size;
		d->longeur = d->square_size * size;
		d->largeur = d->square_size * d->size;
	}
	else if (d->size < size)
	{
		d->square_size = 720 / size;
		d->longeur = d->square_size * size;
		d->largeur = d->square_size * d->size;
	}
}

int	is_element(char c)
{
	if (!(c == 'E' || c == 'C' || c == 'P' || c == '0' || c == '1'))
		return (1);
	return (0);
}

void	set_the_seeting(t_solong *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->size)
	{
		j = -1;
		while (d->map[i][++j])
		{
			if (d->map[i][j] == 'C')
				d->count_collectible++;
			if (d->map[i][j] == 'P')
			{
				d->p_position++;
				d->px = j * d->square_size;
				d->py = i * d->square_size;
				d->map[i][j] = '0';
			}
			if (is_element(d->map[i][j]) == 1)
				d->count_space++;
			if (d->map[i][j] == 'E')
				d->count_exit_door++;
		}
		i++;
	}
}

void	check_size_of_map(t_solong *s)
{
	int		fd;

	s->size = 0;
	fd = open(s->test, O_RDONLY);
	while (get_next_line(fd, &s->line))
	{	
		s->size++;
		free_line(s->line);
	}
	free_line(s->line);
	s->map = malloc(sizeof(char *) * s->size);
	fd = open(s->test, O_RDONLY);
	s->i = -1;
	while (get_next_line(fd, &s->line))
		s->map[++s->i] = s->line;
	free_line(s->line);
	s->i = -1;
	while (++s->i < s->size)
	{
		if (ft_strcmp(s->map[s->i], "") == 0)
			s->error = 1;
		if ((ft_strlen(s->map[s->i]) > ft_strlen(s->map[0]))
			|| (ft_strlen(s->map[s->i]) < ft_strlen(s->map[0])))
			s->error = 1;
	}
}

int	check_error(t_solong *d)
{
	int	i;

	i = -1;
	if (d->error == 1)
	{
		while (++i < d->size)
			free(d->map[i]);
		return (1);
	}
	if (check_contours(d) == 1)
		return (1);
	if (d->count_collectible < 1)
		return (1);
	if (d->p_position != 1)
		return (1);
	if (d->count_exit_door != 1)
		return (1);
	if (d->count_space > 0)
		return (1);
	return (0);
}
