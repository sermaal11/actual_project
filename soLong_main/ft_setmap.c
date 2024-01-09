/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:02:31 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 12:47:30 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_setmap(int fd)
{
    char    *line_map;
    ssize_t map_len;
    char    **map;
    
    line_map = (char *)malloc(BUFFER_SIZE * sizeof(char));
    map_len = read(fd, line_map, BUFFER_SIZE);
    line_map[map_len] = '\0';
    map = ft_split(line_map, '\n');
    if (map == NULL)
		ft_error("No es posible hacer el split.\n");
    free(line_map);
    line_map = NULL;
    return (map);
}
