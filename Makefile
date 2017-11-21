NAME		=	fillit
CC			=	gcc
CFLAGS		=	#-Wall -Werror -Wextra

_OBJS		=	main_v.o \
				ft_solve_tetris.o \
				ft_valid_tetris.o \
				ft_read_tetris.o \
				ft_build_tetris.o \
				ft_absolute_tetris.o \
				ft_print_map.o

SRCS_DIR	=	.
OBJS		=	$(patsubst %,$(SRCS_DIR)/%,$(_OBJS))
SRCS		=	$(OBJS:.o=.c)

LIBFT_DIR	=	libft
LIBFT_NAME	=	libft.a

LIBFT		=	$(patsubst %,$(LIBFT_DIR)/%,$(LIBFT_NAME))

# COLORS
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m
_SUCCESS=$(_GREEN)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "$(_RED)Compiling$(_END) $(NAME) $(_GREEN)...$(_END)"
	@$(CC) $(CFLAGS) -c $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@echo  "$(NAME) : $(_SUCCESS)done$(_END)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@/bin/rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all
