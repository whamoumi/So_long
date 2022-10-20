/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:44:10 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 17:11:39 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 5

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_wall;
	void	*mlx_coin;
	void	*mlx_emp;
	void	*mlx_exit;
	void	*mlx_p;
	char	*data_img;
	char	*data_wall;
	char	*data_coin;
	char	*data_emp;
	char	*data_exit;
	char	*data_p;
	int		bpp;
	int		size_line;
	int		endian;
	int		bpp_wall;
	int		size_line_wall;
	int		endian_wall;
	int		bpp_coin;
	int		size_line_coin;
	int		endian_coin;
	int		bpp_emp;
	int		size_line_emp;
	int		endian_emp;
	int		bpp_exit;
	int		size_line_exit;
	int		endian_exit;
	int		bpp_p;
	int		size_line_p;
	int		endian_p;
	char	**map;
	int		fd;
	char	*line;
	int		i;
	int		largeur;
	int		longeur;
	int		width_wall;
	int		height_wall;	
	int		width_coin;
	int		height_coin;	
	int		width_emp;
	int		height_emp;	
	int		width_exit;
	int		height_exit;	
	int		width_p;
	int		height_p;	
	int		square_size;
	int		modeg;
	int		modeh;
	int		moded;
	int		modeb;
	int		modeesc;
	int		px;
	int		py;
	int		tmp_x;
	int		tmp_y;
	int		count_exit_door;
	int		p_position;
	int		count_collectible;
	int		count_mouvement;
	int		size;
	int		error_code;
	char	*test;
	int		count_space;
	int		x;
	int		y;
	int		error;
}				t_solong;

int				check_error(t_solong *d);
void			check_size_of_map(t_solong *s);
void			set_the_seeting(t_solong *d);
void			give_good_size(t_solong *d);
int				all_mouvement(t_solong *d);
void			mouvement_right(t_solong *d);
void			mouvement_left(t_solong *d);
void			mouvement_down(t_solong *d);
void			mouvement_up(t_solong *d);
void			kill_the_window(t_solong *d);
int				kill_the_windows(t_solong *d);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			my_mlx_pixel_put(t_solong *d, int x, int y, int color);
void			initialize_the_struct(t_solong *d);
int				get_next_line(int fd, char **line);
int				get_rest(char **line, char *str);
char			*creat_line(char *str, char *buffer);
int				is_newline(char *str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
void			so_long_game(t_solong *s);
int				draw(t_solong *d);
void			draw_map(t_solong *d);
char			*free_str(char *str);
int				is_element(char c);
unsigned int	give_color(t_solong *s, int x, int y, int nb);
void			so_long_game(t_solong *s);
void			texture_of_game(t_solong *s);
void			draw_square1(int j, int i, t_solong *d, double y);
void			draw_square2(int j, int i, t_solong *d, double y);
void			draw_square3(int j, int i, t_solong *d, double y);
void			draw_square4(int j, int i, t_solong *d, double y);
int				ber_file_check(char *str);
int				check_contours(t_solong *d);
int				key_press(int keycode, t_solong *s);
int				key_release(int keycode, t_solong *s);
int				key_press(int keycode, t_solong *s);
int				key_release(int keycode, t_solong *s);
void			free_line(char *line);
#endif
