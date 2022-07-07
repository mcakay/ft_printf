NAME=libftprintf.a
LIBFT=libft/libft.a

SRCS= ft_printf.c ft_reset_print.c ft_flag.c ft_check_identifier.c\
ft_put.c ft_reset_print.c ./flags/ft_dash_flag.c ./flags/ft_dot_flag.c\
./flags/ft_number_flag.c ./flags/ft_plus_flag.c ./flags/ft_sharp_flag.c\
./flags/ft_space_flag.c ./flags/ft_zero_flag.c ft_utils.c ft_return.c\
ft_convert.c

OBJS= $(SRCS:.c=.o)

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus