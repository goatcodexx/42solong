/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:12:55 by sywee             #+#    #+#             */
/*   Updated: 2026/11/23 20:58:53 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_everything(t_map *stuff, char *msg)
{
	free_map(stuff->map);
	free(stuff);
	exit(error_msg(msg));
}

void	free_and_exit(t_map *stuff, char *msg)
{
	free(stuff);
	exit(error_msg(msg));
}
