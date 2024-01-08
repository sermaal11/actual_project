# Nombre del programa de salida
NAME = so_long

# Norma de compilación
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Fuentes .c
SRCS = soLong.c

# Ruta a la mlx

MLX = ./mlx/libmlx.a

# Normas que convierten los .c en .o
OBJS = $(SRCS:.c=.o)

# Regla principal para construir el programa principal
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	# Compilar el programa principal usando la biblioteca estática y las 
	# bibliotecas gráficas necesarias
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Regla para compilar archivos .c en objetos .o
%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# REgla MLX

$(MLX) :
	make -C ./mlx

# Regla para limpiar archivos objeto (.o)
clean:
	rm -f *.o
	make clean -C ./mlx

# Regla para limpiar archivos objeto y el programa de salida
fclean: clean
	rm -f $(NAME)

# Regla para limpiar y reconstruir todo
re: fclean all

# Indica que estas reglas no corresponden a archivos reales
.PHONY : clean fclean re #bonus

