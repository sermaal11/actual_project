/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:58:56 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 14:01:28 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Para realizar cualquier accion con la MiniLIbX debemos incluir el encabezado
// <mlx.h> para poder acceder a todas sus funciones.

#include <mlx.h>

// La primera funcion que veremos es mlx_init. Esta funcion establece una
// conexion con el sistema grafico correcto y nos devolvera un *void que 
// contiene la ubicacion de nuestra instancia actual de MLX.
// Para inicializar MiniLibX haremos lo siguiente:

/*
int main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
*/

// Si ejecutamos el codigo anterior, no veremos nada, eso es debido a que aun
// no hemos creado la ventana.
// Para crear una ventana, utilizaremos la funcion mlx_new_window, la cual nos
// devlvera un puntero a la ventana que acabamos de crear.
// A esta ventana, le podemos proporcionar los valores de alto, ancho y un
// titulo.
// Para renderizar la ventana, deberemos llamar a la funcion mlx_loop.
// A continuacion, crearemos una ventana con un ancho de 1920px, un alto
// de 1080px y un titulo que diga "Hola mundo!"

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hola mundo!");
	mlx_loop(mlx);
}
