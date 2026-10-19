/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 19:42:27 by sywee             #+#    #+#             */
/*   Updated: 2026/10/06 20:27:18 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_APP_H
# define FT_MLX_APP_H
# define TILE_SIZE 32
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include <stdlib.h>
# include "minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysymdef.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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

#endif
