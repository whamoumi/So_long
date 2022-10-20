/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:09:07 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:04:05 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square1(int j, int i, t_solong *d, double y)
{
	double	k;
	double	u;
	double	xratio;
	double	yratio;
	double	x;

	y = 0;
	yratio = 0.00;
	u = 86.00 / d->square_size;
	while (y < d->square_size)
	{
		x = 0;
		k = 85.00 / d->square_size;
		xratio = 0.0;
		while (x < d->square_size)
		{
			my_mlx_pixel_put(d, j * d->square_size + x, i * d->square_size + y,
				give_color(d, xratio, yratio, 1));
			xratio += k;
			x++;
		}
		yratio += u;
		y++;
	}
}

void	draw_square2(int j, int i, t_solong *d, double y)
{
	double	k;
	double	u;
	double	xratio;
	double	yratio;
	double	x;

	y = 0;
	yratio = 0.00;
	u = 86.00 / d->square_size;
	while (y < d->square_size)
	{
		x = 0;
		k = 85.00 / d->square_size;
		xratio = 0.0;
		while (x < d->square_size)
		{
			my_mlx_pixel_put(d, j * d->square_size + x, i * d->square_size + y,
				give_color(d, xratio, yratio, 2));
			xratio += k;
			x++;
		}
		yratio += u;
		y++;
	}
}

void	draw_square3(int j, int i, t_solong *d, double y)
{
	double	k;
	double	u;
	double	xratio;
	double	yratio;
	double	x;

	y = 0;
	yratio = 0.00;
	u = 86.00 / d->square_size;
	while (y < d->square_size)
	{
		x = 0;
		k = 85.00 / d->square_size;
		xratio = 0.0;
		while (x < d->square_size)
		{
			my_mlx_pixel_put(d, j * d->square_size + x, i * d->square_size + y,
				give_color(d, xratio, yratio, 3));
			xratio += k;
			x++;
		}
		yratio += u;
		y++;
	}
}

void	draw_square4(int j, int i, t_solong *d, double y)
{
	double	k;
	double	u;
	double	xratio;
	double	yratio;
	double	x;

	y = 0;
	yratio = 0.00;
	u = 86.00 / d->square_size;
	while (y < d->square_size)
	{
		x = 0;
		k = 85.00 / d->square_size;
		xratio = 0.0;
		while (x < d->square_size)
		{
			my_mlx_pixel_put(d, j * d->square_size + x, i * d->square_size + y,
				give_color(d, xratio, yratio, 4));
			xratio += k;
			x++;
		}
		yratio += u;
		y++;
	}
}
