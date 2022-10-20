/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:36:36 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:10:54 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_solong *d)
{
	int		i;
	int		j;
	double	y;

	i = 0;
	j = 0;
	y = 0.0;
	while (i < d->size)
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == '1')
				draw_square1(j, i, d, y);
			if (d->map[i][j] == 'C')
				draw_square2(j, i, d, y);
			if (d->map[i][j] == '0')
				draw_square3(j, i, d, y);
			if (d->map[i][j] == 'E')
				draw_square4(j, i, d, y);
			j++;
		}
		i++;
	}
}

int	ber_file_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (ft_strlen(str) <= 4)
		return (0);
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	kill_the_windows(t_solong *d)
{
	mlx_destroy_window(d->mlx_ptr, d->mlx_win);
	exit (1);
	return (0);
}

int	check_contours(t_solong *d)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(d->map[0]);
	while (i < d->size)
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[0][j] != '1')
				return (1);
			if (d->map[i][0] != '1')
				return (1);
			if (d->map[d->size - 1][j] != '1')
				return (1);
			if (d->map[i][size - 1] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	s;
	int			fd;

	s.error = 0;
	if (argc < 2 || argc > 2)
		return (write(1, "Error\nArguments number\n", 23));
	if (ber_file_check(argv[1]) == 0)
		return (write(1, "Error\nber error\n", 16));
	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
		exit(write(1, "Error\nCeci est un directory\n", 28));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(write(1, "Error\nsur la map\n", 17));
	s.test = argv[1];
	initialize_the_struct(&s);
	check_size_of_map(&s);
	give_good_size(&s);
	set_the_seeting(&s);
	if (check_error(&s) == 1)
		return (write(1, "Error\n", 6));
	else
		so_long_game(&s);
	return (0);
}
