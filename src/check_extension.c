/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:12:10 by sywee             #+#    #+#             */
/*   Updated: 2026/11/19 18:50:19 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *file_name)
{
    int len;
    len = ft_strlen(file_name);
    if (len < 4)
        return(0);
    if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
        return(0);
    return(1);
}
