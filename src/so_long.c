/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:42:19 by sywee             #+#    #+#             */
/*   Updated: 2026/11/27 18:37:24 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_map	*stuff;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
		return (error_msg("Please use: ./so_long [map.ber]"));
	if (!check_extension(av[1]))
		return (error_msg("Invalid file extension [.ber only]"));
	stuff = malloc(sizeof(t_map) * 1);
	if (!stuff)
		return (error_msg("Memory allocation failed"));
	stuff->map = NULL;
	stuff->collectibles = 0;
	stuff->collected = 0;
	if (!read_map(av[1], stuff))
		free_everything(stuff, "Cannot read map");
	check_rows(stuff);
	game.map = stuff;
	init_window(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	free_everything(stuff, NULL);
	return (0);
}
