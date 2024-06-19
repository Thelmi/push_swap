NAME = push_swap

LIBFT = ./libft/libft.a

PRINTF := ./ft_printf/libftprintf.a

SRC = cases_parse_one.c cases_parse_two.c isvalid.c list_helpers.c makemoves.c moves.c \
	  rotate_pushback.c rotation.c sort_five.c sort_three.c sorting_helpers.c sorting_helpers_two.c \
	  target.c rrmakemoves.c program.c\

SRCB = cases_parse_one.c cases_parse_two.c isvalid.c list_helpers.c makemoves.c moves.c \
	  rotate_pushback.c rotation.c sort_five.c sort_three.c sorting_helpers.c sorting_helpers_two.c \
	  target.c rrmakemoves.c checker.c\

OBJ := $(SRC:.c=.o)

OBJB := $(SRCB:.c =.o)

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./ft_printf

re: fclean all

clean:
	rm -rf $(OBJ)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	make fclean -C ./ft_printf

.PHONY: clean fclean all bonus re
