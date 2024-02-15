CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
LIB_DIR = ./libft
NAME = fractol
SRCS = fractol.c draw.c mymlx.c utils.c

$(NAME):
	make all

all: $(SRCS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME) -L$(LIB_DIR) -lft -lftprintf
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

fclean:
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all, fclean, re