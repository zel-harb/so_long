CC = cc
NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lmlx -framework OpenGL -framework AppKit
SOURCES =  main.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  error.c	\
		  spilt.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)
$(NAME) :$(OBJECTS)
		$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) -o $(NAME)
	
clean :
	rm -rf $(OBJECTS)
fclean : clean
		rm -rf $(NAME)
re : fclean all

