/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:42:27 by sywee             #+#    #+#             */
/*   Updated: 2026/11/19 19:21:20 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include <stdlib.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysymdef.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct  s_map
{
    char    **map;
    int     rows;
    int     columns;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     collected;
}           t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *player_img;
    void    *wall_img;
    void    *floor_img;
    void    *collectible_img;
    void    *exit_img;
    int     move_count;
}           t_game;

int error_msg(char *msg);
int check_extension(char *file_name);
int	read_map(char *file, t_map *map);

#endif