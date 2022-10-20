/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:14:39 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/16 13:31:16 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_newline(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (i + 1);
}

char	*creat_line(char *str, char *buffer)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1 + ft_strlen(str)));
	if (!tmp)
		return (NULL);
	if (str)
	{
		while (str[j])
		{
			tmp[j] = str[j];
			j++;
		}
		free(str);
		str = NULL;
	}
	while (buffer[k])
		tmp[j++] = buffer[k++];
	tmp[j] = '\0';
	return (tmp);
}

int	get_rest(char **line, char *str)
{
	char	*rest;
	int		i;

	i = is_newline(str, '\n');
	rest = ft_strchr(str, '\n');
	if (rest)
	{
		*line = ft_substr(str, 0, i);
		ft_strcpy(str, rest + 1);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (str && get_rest(line, str))
		return (1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str = creat_line(str, buffer);
		if (!(str))
			return (-1);
		if (get_rest(line, str))
			return (1);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (str)
		*line = ft_strdup(str);
	else
		*line = ft_strdup("");
	str = free_str(str);
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*strf;
	int				i;
	unsigned int	lens;

	lens = ft_strlen(s);
	i = 0;
	if (start > lens)
	{
		strf = malloc(sizeof(char) * 1);
		if (!strf)
			return (NULL);
		return (strf);
	}
	strf = malloc(sizeof(char) * len + 1);
	if (!strf)
		return (NULL);
	while (s[start] && len != 0)
	{
		if (len == 0)
			return (strf);
		strf[i++] = s[start++];
		len--;
	}
	strf[i] = '\0';
	return (strf);
}
