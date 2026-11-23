/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:56:40 by sywee             #+#    #+#             */
/*   Updated: 2026/11/23 20:40:49 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rows(t_map *stuff)
{
	int	len;
	int	len2;
	int	i;

	i = 1;
	len = ft_strlen(stuff->map[0]);
	stuff->columns = len;
	while (stuff->map[i] != NULL)
	{
		len2 = ft_strlen(stuff->map[i]);
		if (len == len2)
			i++;
		else
			free_everything(stuff, "Invalid map");
	}
	return (1);
}

int	count_char(t_map *stuff, int pce)
{
	int		flag;
	char	*line;
	int		i;
	
	i = 0;
	flag = 0;
	while (stuff->map[i] != NULL)
	{
		line = stuff->map[i];
		while ((ft_strchr(line, pce)) != NULL)
		{
			flag += 1;
			line = ft_strchr(line, pce) + 1;
		}
		// so it won't find the same P again
		i++;
	}
	return (flag);
}

static int	check_valid_chars(t_map *stuff)
{
	char	*line;
	int		i;

	i = 0;
	while (stuff->map[i] != NULL)
	{
		line = stuff->map[i];
		while (*line != '\0')
		{
			if (ft_strchr("01CEP", *line) == NULL)
				free_everything(stuff, "Map contains invalid characters");
			line++;
		}
		i++;
	}
	return (1);
}

int	check_char(t_map *stuff)
{
	int		flag_p;
	int		flag_e;
	int		flag_c;

	check_walls(stuff);
	check_valid_chars(stuff);	
	flag_p = count_char(stuff, 'P');
	flag_e = count_char(stuff, 'E');
	flag_c = count_char(stuff, 'C');
	
	if (flag_c > 0 && flag_p == 1 && flag_e == 1)
		return (0);
	free_everything(stuff, "Invalid characters");
	return (1);
}

int	check_walls(t_map *stuff)
{
	int	i;

	i = 0;
	while (i < stuff->columns)
	{
		if (stuff->map[0][i] != '1' || stuff->map[stuff->rows - 1][i] != '1')
			free_everything(stuff, "Map is not surrounded by walls");
		i++;
	}
	i = 0;
	while (i < stuff->rows)
	{
		if (stuff->map[i][0] != '1' || stuff->map[i][stuff->columns - 1] != '1')
			free_everything(stuff, "Map is not surrounded by walls");
		i++;
	}
	return (1);
}
