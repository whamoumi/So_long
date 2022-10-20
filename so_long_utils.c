/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:55:12 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:04:52 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_the_struct(t_solong *d)
{
	d->count_exit_door = 0;
	d->p_position = 0;
	d->count_collectible = 0;
	d->count_mouvement = 0;
	d->count_space = 0;
	d->px = 0;
	d->py = 0;
}

void	kill_the_window(t_solong *d)
{
	int	kill;

	kill = mlx_destroy_window (d->mlx_ptr, d->mlx_win);
	exit (0);
}

void	ft_putnbr(int nb)
{
	int	nbr;

	nbr = nb * -1;
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
	else if (nb <= 9 && nb >= 0)
	{
		ft_putchar('0' + nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	my_mlx_pixel_put(t_solong *d, int x, int y, int color)
{
	char	*dst;

	dst = d->data_img + (y * d->size_line + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}
