/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:46:09 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:04:23 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouvement_up(t_solong *d)
{
	d->py -= d->square_size;
	d->px -= 0;
	d->count_mouvement++;
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'C')
	{
		d->map[(d->py / d->square_size)][(d->px / d->square_size)] = '0';
		d->count_collectible--;
	}
	if ((d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'E')
		&& (d->count_collectible == 0))
	{
		write(1, "CONGRATULATION\n", 16);
		mlx_destroy_window (d->mlx_ptr, d->mlx_win);
		exit (1);
	}
	ft_putnbr(d->count_mouvement);
	write(1, "\n", 1);
}

void	mouvement_down(t_solong *d)
{
	d->py += d->square_size;
	d->px += 0;
	d->count_mouvement++;
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'C')
	{
		d->map[(d->py / d->square_size)][(d->px / d->square_size)] = '0';
		d->count_collectible--;
	}
	if ((d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'E')
		&& (d->count_collectible == 0))
	{
		write(1, "CONGRATULATION\n", 16);
		mlx_destroy_window (d->mlx_ptr, d->mlx_win);
		exit (1);
	}
	ft_putnbr(d->count_mouvement);
	write(1, "\n", 1);
}

void	mouvement_left(t_solong *d)
{
	d->py += 0;
	d->px -= d->square_size;
	d->count_mouvement++;
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'C')
	{
		d->map[(d->py / d->square_size)][(d->px / d->square_size)] = '0';
		d->count_collectible--;
	}
	if ((d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'E')
		&& (d->count_collectible == 0))
	{
		write(1, "CONGRATULATION\n", 16);
		mlx_destroy_window (d->mlx_ptr, d->mlx_win);
		exit (1);
	}
	ft_putnbr(d->count_mouvement);
	write(1, "\n", 1);
}

void	mouvement_right(t_solong *d)
{
	d->py += 0;
	d->px += d->square_size;
	d->count_mouvement++;
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'C')
	{
		d->map[(d->py / d->square_size)][(d->px / d->square_size)] = '0';
		d->count_collectible--;
	}
	if ((d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'E')
		&& (d->count_collectible == 0))
	{
		write(1, "CONGRATULATION\n", 16);
		mlx_destroy_window (d->mlx_ptr, d->mlx_win);
		exit (1);
	}
	ft_putnbr(d->count_mouvement);
	write(1, "\n", 1);
}

int	all_mouvement(t_solong *d)
{
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size) - 1] != '1')
		if (d->modeg == 1)
			mouvement_left(d);
	if (d->map[(d->py / d->square_size)][(d->px / d->square_size) + 1] != '1')
		if (d->moded == 1)
			mouvement_right(d);
	if (d->map[(d->py / d->square_size) - 1][(d->px / d->square_size)] != '1')
		if (d->modeh == 1)
			mouvement_up(d);
	if (d->map[(d->py / d->square_size) + 1][(d->px / d->square_size)] != '1')
		if (d->modeb == 1)
			mouvement_down(d);
	if (d->modeesc == 1)
		kill_the_window(d);
	if ((d->map[(d->py / d->square_size)][(d->px / d->square_size)] == 'E')
		&& (d->count_collectible != 0))
		write(1, "il te manque des pieces a recuperer\n", 37);
	return (1);
}
