/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:20:37 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 17:07:29 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 INTRODUCCION

 Los eventos son la base para escribir aplicaciones interactivas en MiniLibX.
 Es esencial comprender completamente este capitulo, ya que nos sera de
 gran utilidad en futuros proyectos graficos.

 Las funciones que se llaman cuando se desencadena un evento son llamadas hooks.
 No es necesario dominar todas, sin embargo las repasaremos de acuerdo con X11.

 Nota: Enla version MacOS (Cocoa (appKit y OpenGL) MiniLibX tiene soporte 
 parcial de eventos de X11 y no admite la mascara X11 (es decir, el argumento
 x_mask de mlx_hook no tiene utilidad, por lo que lo dejaremos en 0).

 Eventos compatibles:

 enum {
 	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12, 
	ON_DESTROY = 17
 };

 Manera de uso:

 mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
 */

/*
 EVENTOS X11

 X11 es la biblioteca que se utiliza junto a MiniLibX. Por lo tanto, es muy
 util para encontrar todos los eventos correspondientes de MIniLibX

 Podemos ver todos los evetos en la siguiente direccion:

 https://harm-smits.github.io/42docs/libs/minilibx/events.html#x11-events
*/

/*
 MASCARAS DE X11

 Cada evento de X11 tambien tiene una mascars correspondiente. De esta manera
 podemos resgistrar solo cuando una tecla se activa, o para todas la teclas si
 dejamos la mascara en el valor predeterminado.
 Por lo tanto, las mascaras de teclas permiten incluir o excluir eventos de
 nuestras suscripciones a eventos.

 En la siguiente direccion podemos ver las mascara permitidas:

 https://harm-smits.github.io/42docs/libs/minilibx/events.html#x11-masks
*/

/*
 ENGANCHARSE A EVENTOS

 Engancharse a eventos es una de las herramientas mas poderosas que nos
 proporciona MiniLibX.
 Esta herramienta nos permite registrarno en cualquiera de los eventos
 mencionados anteriormente con una simple llamada a una funcion de 
 registro de gancho.

 Las funciones de evento tienen un prototipo diferente dependiendo del evento
 de enganche.

 Podemos consultar estos prototipos en la siguiente direccion:

 https://harm-smits.github.io/42docs/libs/minilibx/events.html#prototype-of-event-functions

 Ademas, la API de MiniLibX tiene algunas funciones de enganche con alias:

 - mlx_expose_hook es un alias en el evento de exposicion (12).
 - mlx_key_hook es un alias en el evento de tecla presionada (3).
 - mlx_mouse_hook es un alias en el evento clik de raton (4).
 */

/*
 EJEMPLO
*/

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// Funcion para cerrar la ventana pulsando la tecla ESC.
int	esc_close(int keycode, t_vars *vars)
{
	if (keycode == 53)	// 53 es el codigo para la tecla ESC
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);		// Mediante la funcion exit cerramos el proceso
	}
	return (0);
}

// Funcion para cerrar la ventana pulsando la x roja.
int x_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return(0);
}

/*
// Funcion para redimensionar al doble la pantalla mediante la tecla F.

int set_max_screen(int keycode, t_vars *vars)
{
	if (keycode == 3)
	{
		printf("Pantalla redimensionada\n");
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Fullscreen");
		mlx_hook(vars->win, 2, 1L<<0, esc_close, vars);
		mlx_hook(vars->win, 17, 1L<<17, x_close, vars);
	}
	return (0);
}
*/

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 540, "Events");
	mlx_hook(vars.win, 2, 1L<<0, esc_close, &vars);
	mlx_hook(vars.win, 17, 1L<<17, x_close, &vars);
//	mlx_hook(vars.win, 2, 1L<<0, set_max_screen, &vars);
	mlx_loop(vars.mlx);
}
