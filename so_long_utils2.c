/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:28:03 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:05:03 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

unsigned int	give_color(t_solong *s, int x, int y, int nb)
{
	char	*dest;

	if (nb == 1)
		dest = s->data_wall + (y * s->size_line_wall + x * (s->bpp_wall / 8));
	if (nb == 2)
		dest = s->data_coin + (y * s->size_line_coin + x * (s->bpp_coin / 8));
	if (nb == 3)
		dest = s->data_emp + (y * s->size_line_emp + x * (s->bpp_emp / 8));
	if (nb == 4)
		dest = s->data_exit + (y * s->size_line_exit + x * (s->bpp_exit / 8));
	if (nb == 5)
		dest = s->data_p + (y * s->size_line_p + x * (s->bpp_p / 8));
	return (*(unsigned int *)dest);
}

void	texture_of_game(t_solong *s)
{
	s->mlx_img = mlx_new_image(s->mlx_ptr, s->longeur, s->largeur);
	s->data_img = mlx_get_data_addr(s->mlx_img, &s->bpp, &s->size_line,
			&s->endian);
	s->mlx_wall = mlx_xpm_file_to_image(s->mlx_ptr, "./wall.xpm",
			&s->width_wall, &s->height_wall);
	s->data_wall = mlx_get_data_addr(s->mlx_wall, &s->bpp_wall,
			&s->size_line_wall, &s->endian_wall);
	s->mlx_coin = mlx_xpm_file_to_image(s->mlx_ptr, "./coins.xpm",
			&s->width_coin, &s->height_coin);
	s->data_coin = mlx_get_data_addr(s->mlx_coin, &s->bpp_coin,
			&s->size_line_coin, &s->endian_coin);
	s->mlx_emp = mlx_xpm_file_to_image(s->mlx_ptr, "./empty_area.xpm",
			&s->width_emp, &s->height_emp);
	s->data_emp = mlx_get_data_addr(s->mlx_emp, &s->bpp_emp,
			&s->size_line_emp, &s->endian_emp);
	s->mlx_exit = mlx_xpm_file_to_image(s->mlx_ptr, "./exit_door.xpm",
			&s->width_exit, &s->height_exit);
	s->data_exit = mlx_get_data_addr(s->mlx_exit, &s->bpp_exit,
			&s->size_line_exit, &s->endian_exit);
	s->mlx_p = mlx_xpm_file_to_image(s->mlx_ptr, "./gauche.xpm",
			&s->width_p, &s->height_p);
	s->data_p = mlx_get_data_addr(s->mlx_p, &s->bpp_p,
			&s->size_line_p, &s->endian_p);
}

void	so_long_game(t_solong *s)
{
	s->mlx_ptr = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx_ptr, s->longeur, s->largeur, "ber");
	texture_of_game(s);
	mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->mlx_img, 0, 0);
	mlx_hook(s->mlx_win, 2, (1L << 0), key_press, s);
	mlx_hook(s->mlx_win, 3, (1L << 1), key_release, s);
	mlx_hook(s->mlx_win, 17, 0, kill_the_windows, s);
	mlx_loop_hook(s->mlx_ptr, draw, s);
	mlx_loop(s->mlx_ptr);
}

int	draw(t_solong *d)
{
	double	yratio;
	double	u;
	double	k;
	double	xratio;

	draw_map(d);
	all_mouvement(d);
	yratio = 0.0;
	d->y = -1;
	u = 86.00 / d->square_size;
	while (++d->y < d->square_size)
	{
		d->x = -1;
		k = 85.00 / d->square_size;
		xratio = 0.0;
		while (++d->x < d->square_size)
		{
			my_mlx_pixel_put(d, d->px + d->x, d->py + d->y,
				give_color(d, xratio, yratio, 5));
			xratio += k;
		}
		yratio += u;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->mlx_img, 0, 0);
	return (0);
}
