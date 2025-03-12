NAME	=	libftprintf.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
SRC	=	ft_printf.c ft_utils.c ft_print_unbr.c ft_print_ptr.c ft_print_nbr.c ft_print_hex.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
