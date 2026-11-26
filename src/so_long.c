/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:42:19 by sywee             #+#    #+#             */
/*   Updated: 2026/11/25 21:53:24 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* # define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_data;

static int  ft_close(t_data *data)
{
    if (data)
    {
        if (data->win_ptr)
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        if (data->mlx_ptr)
        {
            mlx_destroy_display(data->mlx_ptr);
            free(data->mlx_ptr);
        }
    }
    exit(0);
    return (0);
}

int ft_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)
        ft_close(data);
    return(0);
}

Old MLX test code from main, kept for reference:

    t_data  data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    return(1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello 42");
    if (!data.win_ptr)
    {
        free(data.mlx_ptr);
        return(1);
    }
    mlx_hook(data.win_ptr, 17, 1 << 17, &ft_close, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_keypress, &data);
	mlx_loop(data.mlx_ptr); */

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
	check_path(stuff);
	game.map = stuff;
	init_window(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	free_everything(stuff, NULL);
	return (0);
}
