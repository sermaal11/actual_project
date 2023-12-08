# Nombre del programa de salida
NAME = so_long.a

# Norma de compilación
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror

# Fuentes .c
SRCS =

# Normas que convierten los .c en .o
OBJS = $(SRCS:.c=.o)

# Regla principal para construir el programa principal
all: $(NAME)

$(NAME): $(OBJS)
	# Crear una biblioteca estática con los objetos (.o)
	ar -crs $@ $^
	# Compilar el programa principal usando la biblioteca estática y las 
	# bibliotecas gráficas necesarias
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

# Regla para compilar archivos .c en objetos .o
%.o : %.c
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

# Regla para limpiar archivos objeto (.o)
clean:
	rm -f *.o

# Regla para limpiar archivos objeto y el programa de salida
fclean: clean
	rm -f $(NAME)

# Regla para limpiar y reconstruir todo
re: fclean all

# Indica que estas reglas no corresponden a archivos reales
.PHONY : clean fclean re #bonus

