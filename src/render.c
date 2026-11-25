/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 21:47:56 by sywee             #+#    #+#             */
/*   Updated: 2026/11/25 22:28:47 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_tile(t_game *game, int x, int y)
{
	char	c;

	c = game->map->map[y][x];
	put_img(game, game->floor_img, x, y);
	if (c == '1')
		put_img(game, game->wall_img, x, y);
	else if (c == 'C')
		put_img(game, game->collectible_img, x, y);
	else if (c == 'E')
		put_img(game, game->exit_img, x, y);
	else if (c == 'P')
		put_img(game, game->player_img, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
