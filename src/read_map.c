/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:20:21 by sywee             #+#    #+#             */
/*   Updated: 2026/11/23 21:03:59 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_map(char *file, t_map *stuff)
{
	int		fd;
	int		i;
	char	*line;

	stuff->rows = count_rows(file);
	if (stuff->rows <= 2)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_and_exit(stuff, "File cannot open");
	stuff->map = malloc(sizeof(char *) * (stuff->rows + 1));
	if (!stuff->map)
		return (close(fd), 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		strip_newline(line);
		stuff->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	stuff->map[i] = NULL;
	return (close(fd), 1);
}

void	strip_newline(char *line)
{
	char	*nl;

	nl = ft_strchr(line, '\n');
	if (nl == NULL)
		return ;
	nl[0] = '\0';
}
