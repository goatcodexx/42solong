/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:43:52 by sywee             #+#    #+#             */
/*   Updated: 2026/11/27 17:16:59 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		free_game(game, "Failed to load texture");
	return (img);
}

void	load_textures(t_game *game)
{
	game->wall_img = load_image(game, "textures/wall.xpm");
	game->floor_img = load_image(game, "textures/floor.xpm");
	game->player_img = load_image(game, "textures/player.xpm");
	game->player_left_img = load_image(game, "textures/player_left.xpm");
	game->collectible_img = load_image(game, "textures/collectible.xpm");
	game->exit_img = load_image(game, "textures/exit.xpm");
}

static void	check_screen_size(t_game *game, int width, int height)
{
	int		screen_w;
	int		screen_h;
	char	*msg;

	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	msg = NULL;
	if (width > screen_w)
		msg = "Map is wider than screen";
	else if (height > screen_h)
		msg = "Map is taller than screen";
	if (msg)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_everything(game->map, msg);
	}
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		free_everything(game->map, "MLX init failed");
	width = game->map->columns * TILE_SIZE;
	height = game->map->rows * TILE_SIZE;
	check_screen_size(game, width, height);
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_everything(game->map, "Window creation failed");
	}
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_key, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_game, game);
	load_textures(game);
}
