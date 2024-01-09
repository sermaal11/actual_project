/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:31:17 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 17:25:25 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;
    char **map;
    
    if (ft_verify_extension(argv[1]) != 0)
        ft_error("Extension invalida.\n");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error("Error en la apertura de el archivo.\n");
    map = ft_setmap(fd);
    ft_init_map_verify(map);
    close(fd);
    system("leaks -q so_long");
    return (0);
}
