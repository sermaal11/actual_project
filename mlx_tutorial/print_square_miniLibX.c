/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square_miniLibX.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:28:34 by smarin-a          #+#    #+#             */
/*   Updated: 2023/12/08 19:28:48 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 cc -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit nombre_archivo.c
*/
/*
 https://harm-smits.github.io/42docs/libs/minilibx
*/

#include <mlx.h>

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

// Funcion para dibujar un pixel en la pantalla
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// FUncion para dibujar una linea horizontal en la pantalla
void draw_horizontal_line(t_data *data, int x, int y, int width, int color)
{
	while (width-- > 0)
	{	
		my_mlx_pixel_put(data, x++, y, color);
	}
}

// Funcion para dibujar una linea vertical en la pantall
void draw_vertical_line(t_data *data, int x, int y, int height, int color)
{
	while (height-- > 0)
	{
		my_mlx_pixel_put(data, x , y++, color);
	}
}


//Funcion para dibujar un cuadrado en la pantalla
void draw_square(t_data *data, int xc, int yc, int size, int color)
{
	int half_size = size / 2;

	draw_horizontal_line(data, xc - half_size, yc - half_size, size, color);
	draw_horizontal_line(data, xc - half_size, yc + half_size, size, color);
	draw_vertical_line(data, xc - half_size, yc - half_size, size, color);
	draw_vertical_line(data, xc + half_size, yc - half_size, size, color);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_square(&img, 400, 300, 100, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
