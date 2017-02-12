/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:04:15 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:47:21 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static t_fd	*initialize(void)
{
	int		i;
	t_fd	*tmp;

	i = 0;
	if ((tmp = (t_fd*)malloc(sizeof(t_fd))) == NULL)
		return (NULL);
	while (i < 5000)
	{
		if ((tmp->stock[i] = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
		tmp->stock[i][0] = '\0';
		i++;
	}
	return (tmp);
}

static int	reading(int fd, t_fd **tatic)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin((*tatic)->stock[fd], buf);
		ft_strdel(&(*tatic)->stock[fd]);
		(*tatic)->stock[fd] = tmp;
	}
	return (ret);
}

static int	last_tatic(t_fd **tatic, int fd, char **line)
{
	if ((*tatic)->stock[fd][0] != '\0')
	{
		*line = ft_strdup((*tatic)->stock[fd]);
		(*tatic)->stock[fd][0] = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd		*tatic = NULL;
	char			*tmp;
	int				ret;

	ret = 1;
	tmp = NULL;
	if (fd < 0 || line == NULL || read(fd, tmp, 0) == -1)
		return (-1);
	if (tatic == NULL)
		tatic = initialize();
	while (ret > 0)
	{
		if ((tmp = ft_strchr(tatic->stock[fd], '\n')) != NULL)
		{
			*line = ft_strndup(tatic->stock[fd], (tmp - tatic->stock[fd]));
			*tmp = '\0';
			ft_memmove(tatic->stock[fd], tmp + 1, ft_strlen(tmp + 1) + 1);
			return (1);
		}
		ret = reading(fd, &tatic);
	}
	return (last_tatic(&tatic, fd, line) ? 1 : ret);
}
