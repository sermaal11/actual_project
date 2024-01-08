/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:51:22 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 19:57:11 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 INTRODUCCION
 
 Las imagenes son una herramienta muy importantes en MiniLibX para aprovechar
 todo su potencial. Estas funciones te permitiran leer archivos directamente 
 en un objeto de imagen. Esto es muy util, por supuesto, para texturas o 
 sprites.
*/

/*
 LEYENDO IMAGENES

 Para leer desde un archivo a un objeto de imagen, necesitas utilizar los
 formatos XPM o PNG. Para realizar la lectura, podemos llamar a las funciones
 mlx_xpm_file_to_image o mlx_png_file_to_image respectivamente.
 Hemos de tener en cuenta que la segunda suele tenes memory leaks. Ambas
 funciones aceptan exactamente los mismos parametros y su uso es identico.
*/

#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path = "./hobbit.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hobbit");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 250, 250);
	mlx_loop(mlx);
	return (0);
}
