NAME=libftprintf.a
LIBFT=libft/libft.a

SRCS= ft_printf.c ft_reset_print.c ft_put.c ft_flag.c ft_return.c ft_utils.c\
ft_dash_flag.c ft_width_flag.c ft_calc_size.c ft_zero_flag.c ft_precision_flag.c\
ft_convert.c ft_plus_flag.c ft_space_flag.c ft_sharp_flag.c

BONUS_SRCS= ft_printf.c ft_reset_print.c ft_put.c ft_flag.c ft_return.c ft_utils.c\
ft_dash_flag.c ft_width_flag.c ft_calc_size.c ft_zero_flag.c ft_precision_flag.c\
ft_convert.c ft_plus_flag.c ft_space_flag.c ft_sharp_flag.c

OBJS= $(SRCS:.c=.o)

BONUS_OBJS= $(SRCS:.c=.o)

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus