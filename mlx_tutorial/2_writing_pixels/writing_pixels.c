/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:02:00 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 14:56:01 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

/*
 En este apartado veremos como enviar pixeles a la ventana. La forma de
 imprimier estos pixeles depende completamente de nosotros, sin embargo, 
 vamos a ver diferentes formas optimizadas de hacerlo.
 En primer lugar, debemos tener en cuenta que la funcion mlx_put_pixel es 
 muy lenta. Esto se debe a que intenta enviar el pixel instantaneamente a la
 ventana (sin esperar a que la pantalla haya renderizado por completo).
 Es por esta razon, por la que deberemos alamacer primero todos los pixeles
 y luego enviarlos.

 En primer lugar, deberemos comenzar por entender que tipo de imagen requiere
 MiniLibX.
 Si iniciamos una imagen, tendremos que pasarle algunos punteros en los
 cuales se escribiran algunas variables importantes.
 La primera variable se llamara bpp (bit per pixel). Dado que los pixels son
 basicamente variables tipo int, estos son 4 bytes, sin embargo, esto puede 
 variar si estamos tratando con un little-endian (lo que significa que
 probablemente estemos trabanjando en una pantalla remota y solo tenemos
 colores de 8 bits).

 Antes de nada, inicializaremos una imgageb con un tamaño de 1920x1080
*/

/*
int main(void)
{
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
}
*/

/*
 Una vez hemos inicializado la imagen, necesitamos obtener la direccion de
 memoria en la que mutaremos los bytes correspondientemente.
 Para ello, reccuperaremos la esta direccion de la siguiente manerea:
*/


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
int main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	// Despues de crear una imagen, podremos llamar a la funcion
	// mlx_get_data_addr, a la cual le pasaremos las variables bits_per_pixel, 
	// line_length y endian por referencia.
	// Asi estos se estableceran en consecuencia para la direccion de datos
	// actual.
	
	img.addr = mlx_get_dat_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

}
*/

/*
 Ahora ya tenemos la direccion de la imagen, pero aun no hay pixeles.
 Antes de comenzar con esto, debemos entender que los bytes no estan alineados,
 esto significa que la line_length difiere del ancho real de la ventana.
 Por lo tanto, SIEMPRE debemos calcular el desplazamiento de memoria utilizando
 la line_length establecida por mlx_get_data_addr.
 Podemos calcularla facilmente usando la siguiente formula:

 int offset = (y * line_length + x * (bits_per_pixel / 8));

 Una vez hecho esto, crearemos una funcion que imite el comportamiento de la 
 funcion mlx_pixel_put pero que sea mucho mas rapida.
*/

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr +  (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
 Hemos de tener en cuenta que esto causara un problema. Debido a que una imagen
 se representara en tiempo real en una ventana, cambiar la misma imagen causara
 una serie de problemas de desgarro de pantalla al escribir en ella.
 Por lo tanto, deberemos crear dos o mas imagens para contener temporalmente
 nuestros fotogramas. De esta manera. podremos escribir en una imagen temporal,
 para no tener que sobreescribir en la imagente que este presentada en ese 
 momento.
*/

/*
 Una vez visto esto, vamos a ver como pintar un pixel rojo en la coodenadas
 (5,5).
*/

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "write pixel");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
