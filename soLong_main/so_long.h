/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:16:22 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/09 17:08:05 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define BUFFER_SIZE 1000

void    ft_error(char *str);
int     ft_strlen(const char *str);
int     ft_verify_extension(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char    **ft_setmap(int fd);
void    ft_init_map_verify(char **map);
int     ft_strlen_vert(char **map);
int     ft_count_objects(char **map, int c);
char    **ft_player_position(char **map);
