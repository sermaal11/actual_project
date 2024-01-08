/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:43:25 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/08 18:16:46 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 INTRODUCCION

 El "hooking" se utiliza para diversos fines, como depuracion y ampliacion de
 funcionalidades.
 Como ejemplos se podrian incluir la interceptacion de mensajes de eventos de
 teclado o de raton antes de que lleguen a la aplicacion.

 El "hooking" es el pilar de la MiniLibX.
 */

/*
 HOOKING EN EVENTOS DE TECLADO Y RATON
*/

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

// Funcion mapeo WASD.
int key_hook(int keycode)
{
	if (keycode == 0)
		printf("A\n");
	else if (keycode == 1)
		printf("S\n");
	else if (keycode == 2)
		printf("D\n");
	else if (keycode == 13)
		printf("W\n");
	return (0);
}

// Funcion mapeo raton
int mouse_hook(int keycode)
{
	if (keycode == 1)
		printf("Left clik.\n");
	else if (keycode == 2)
		printf("Right clik.\n");
	else if (keycode == 3)
		printf("Middle clik.\n");
	else if (keycode == 4)
		printf("Scroll up.\n");
	else if (keycode == 5)
		printf("Scroll down.\n");
	return (0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "hooks");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, esc_close, &vars);
	mlx_hook(vars.win, 17, 1L<<17, x_close, &vars);
	mlx_loop(vars.mlx);
}
