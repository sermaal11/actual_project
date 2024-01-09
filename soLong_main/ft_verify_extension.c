/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:21 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 16:48:57 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Funcion que verifica si la extension del mapa es correcta

int ft_verify_extension(const char *str)
{
    int len;

    len = ft_strlen(str);
    if (str[len - 1] == 'r')
    {
        if (str[len - 2] == 'e')
        {
            if (str[len - 3] == 'b')
            {
                if (str[len - 4] == '.')
                    return (0);
                else
                    return (1);
            }
            else
                return (1);
        }
        else
            return (1);
    }
    else
        return (1);
}
