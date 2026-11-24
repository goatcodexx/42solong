/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:00:00 by sywee             #+#    #+#             */
/*   Updated: 2026/11/24 14:00:00 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_map *stuff)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (stuff->rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < stuff->rows)
	{
		copy[i] = ft_strdup(stuff->map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, y - 1, x);
	fill(map, y + 1, x);
	fill(map, y, x - 1);
	fill(map, y, x + 1);
}

static int	has_unreached(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_path(t_map *stuff)
{
	char	**copy;

	copy = copy_map(stuff);
	if (!copy)
		free_everything(stuff, "Memory allocation failed");
	fill(copy, stuff->player_y, stuff->player_x);
	if (has_unreached(copy))
	{
		free_map(copy);
		free_everything(stuff, "No valid path");
	}
	free_map(copy);
}
