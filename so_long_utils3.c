/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:59:19 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 16:51:34 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_solong *s)
{
	if (keycode == 0)
		s->modeg = 0;
	if (keycode == 1)
		s->modeb = 0;
	if (keycode == 2)
		s->moded = 0;
	if (keycode == 13)
		s->modeh = 0;
	if (keycode == 53)
		s->modeesc = 0;
	return (1);
}

int	key_press(int keycode, t_solong *s)
{
	if (keycode == 0)
		s->modeg = 1;
	if (keycode == 1)
		s->modeb = 1;
	if (keycode == 2)
		s->moded = 1;
	if (keycode == 13)
		s->modeh = 1;
	if (keycode == 53)
		s->modeesc = 1;
	return (1);
}

void	free_line(char *line)
{
	free(line);
	line = NULL;
}
