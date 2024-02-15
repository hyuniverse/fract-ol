CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
LIB_DIR = ./libft
NAME = fractol
SRCS = fractol.c draw.c mymlx.c utils.c
OBJS = fractol.o draw.o mymlx.o utils.o
INCLUDE = fractol.h

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME) -L$(LIB_DIR) -lft -lftprintf

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re