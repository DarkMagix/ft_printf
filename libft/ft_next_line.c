/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 14:27:04 by mweir             #+#    #+#             */
/*   Updated: 2018/05/14 14:33:04 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sep_nl(char **str, char **line, int fd, int result)
{
	char	*tmp_str;
	int		size;

	size = 0;
	while (str[fd][size] != '\n' && str[fd][size] != '\0')
		size++;
	if (str[fd][size] == '\n')
	{
		*line = ft_strsub(str[fd], 0, size);
		tmp_str = ft_strdup(str[fd] + size + 1);
		free(str[fd]);
		str[fd] = tmp_str;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][size] == '\0')
	{
		if (result == BUFF_SIZE)
			return (ft_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		ft_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			result;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((result = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[result] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (result < 0)
		return (-1);
	else if (result == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_sep_nl(str, line, fd, result));
}
