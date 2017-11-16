NAME		=	fillit
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

_OBJS		=	main.o \
				fillit.o \
				ft_get_tetris.o \
				ft_resolve_tetris.o \
				ft_print_tetris.o

SRCS		=	.
OBJS		=	$(patsubst %,$(SRCS)/%,$(_OBJS))

LIBFT_DIR	=	libft
LIBFT_NAME	=	libft.a

LIBFT		=	$(patsubst %,$(LIBFT_DIR)/%,$(LIBFT_NAME))
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SRCS)/%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	/bin/rm -f $(NAME) 
	make fclean -C $(LIBFT_DIR)

re: fclean all
