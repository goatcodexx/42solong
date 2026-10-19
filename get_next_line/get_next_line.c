/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:53:49 by sywee             #+#    #+#             */
/*   Updated: 2026/03/09 17:51:41 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*readd(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (bytes_read == 0 || ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash, int *len)
{
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[*len] != '\0' && stash[*len] != '\n')
		(*len)++;
	if (stash[*len] == '\n')
		(*len)++;
	line = ft_substr(stash, 0, *len);
	return (line);
}

static char	*update_stash(char *stash, int len)
{
	char	*newline;

	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	newline = ft_strdup(stash + len);
	free(stash);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = readd(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash, &len);
	stash = update_stash(stash, len);
	return (line);
}

/* int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
} */
