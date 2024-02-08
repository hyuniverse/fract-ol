CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

NAME = fractol
SRCS = fractol.c mymlx.c utils.c

$(NAME):
	make all

all: $(SRCS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

fclean:
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all, fclean, re