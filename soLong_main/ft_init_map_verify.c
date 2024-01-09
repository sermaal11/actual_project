/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_verify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:55:41 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 17:25:23 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_verify_rectangle(char **map)
{
    int row;
    int len;
    
    row = 0;
    len = ft_strlen(map[0]);
    while (map[row] != NULL)
    {
        if (len != ft_strlen(map[row]))
            ft_error("Mapa invallido.\n");
        row++;
    }
}

static void ft_verify_wall(char **map)
{
    int row;
    int col;

    row = 0;
    while (map[row] != NULL)
    {
        col = 0;
        while(map[row][col] != '\0')
        {
            if (map[0][col] != '1' || map[ft_strlen_vert(map) - 1][col] != '1')
                ft_error("Mapa invalido.\n");
            if (map[row][0] != '1' || map[row][ft_strlen(map[row]) - 1] != '1')
                ft_error("Mapa invalido.\n");
            col++;
        }
        row++;
    }
}

static void ft_verify_objects(char **map)
{
    int c;
    int e;
    int p;

    c = ft_count_objects(map, 'C');
    if (c < 1)
        ft_error("Mapa invalido.\n");
    e = ft_count_objects(map, 'E');
    if (e != 1)
        ft_error("Mapa invalido.\n");
    p = ft_count_objects(map, 'P');
    if (p != 1)
        ft_error("Mapa invalido.\n");
}

static void ft_verify_path(char **map)
{
    char **player_position;

    player_position = ft_player_position(map);
    printf("%c", player_position);
}

void    ft_init_map_verify(char **map)
{
    ft_verify_rectangle(map);
    ft_verify_wall(map);
    ft_verify_objects(map);
    ft_verify_path(map);
}
