NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	pipex.c \

OBJ =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C libft/
	@make -s -C ft_printf/
	@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

fclean: clean
	@make fclean -s -C libft/
	@make fclean -s -C ft_printf/
	@rm -rf $(NAME)

clean:
	@make clean -s -C ft_printf/
	@make clean -s -C libft/
	@rm -rf $(OBJ)

re: fclean all