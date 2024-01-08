/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:31:17 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 21:09:37 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int ft_strlen(const char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

/*
Funcion que verifica si la extension del mapa es correcta
*/
int verify_extension(const char *str)
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
                    return (1);
                else
                    return (0);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (0);
}

int main(int argc, char **argv)
{
    if (verify_extension(argv[1]) == 1)
    {
        printf("Extension correcta.\n");
    }
    else
    {
        printf("Extension incorrecta.\n");
    }     
    return (0);
}
