CC = cc 
NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lmlx -framework OpenGL -framework AppKit
SOURCES = main.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  error.c	\
		  split.c	\
		  window.c	\
		  use_error.c\
		  exit.c	\
		  moves.c	\
		  put_img_pxl.c \
		  free.c	\
		  ./ft_printf/ft_printf.c \
		  	./ft_printf/ft_putaddr.c \
		  	./ft_printf/ft_putchar.c \
		 	./ft_printf/ft_putnbr_base.c \
		  	./ft_printf/ft_putnbr_unsigned.c \
		  	./ft_printf/ft_putnbr.c \
		  	./ft_printf/ft_putstr.c

BSOURCES = 	./bonus/main_bonus.c \
		  	./bonus/get_next_line_bonus.c \
		  	./bonus/get_next_line_utils_bonus.c \
		  	./bonus/error_bonus.c	\
		  	./bonus/split_bonus.c	\
		  	./bonus/window_bonus.c	\
		  	./bonus/use_error_bonus.c\
		 	./bonus/exit_bonus.c	\
		  	./bonus/moves_bonus.c	\
			./bonus/animation.c \
			./bonus/check_error_img.c \
			./bonus/free_bonus.c	\
			./bonus/animation_moves.c \
			./bonus/utils.c	\
		  	./bonus/ft_printf/ft_printf.c \
		  	./bonus/ft_printf/ft_putaddr.c \
		  	./bonus/ft_printf/ft_putchar.c \
		 	./bonus/ft_printf/ft_putnbr_base.c \
		  	./bonus/ft_printf/ft_putnbr_unsigned.c \
		  	./bonus/ft_printf/ft_putnbr.c \
		  	./bonus/ft_printf/ft_putstr.c 

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all : $(NAME)

$(NAME) :$(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

bonus : $(BOBJECTS)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(BOBJECTS)  -o $(NAME)
clean :
	rm -rf $(OBJECTS) $(BOBJECTS)
fclean : clean
		rm -rf $(NAME)
re : fclean all

