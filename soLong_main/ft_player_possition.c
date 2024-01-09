/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_possition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:06:18 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 17:11:12 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_player_position(char **map)
{
    int row;
    int col;
    char **player_position;
    
    row = 0;
    while (map[row] != NULL)
    {
        col = 0;
        while(map[row][col] != '\0')
        {
            if (map[row][col] == 'P')
            {
                player_position = map[row][col];
                return (player_position);
            }
            col++;
        }
        row++;
    }
}
