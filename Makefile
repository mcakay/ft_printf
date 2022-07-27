NAME=libftprintf.a
LIBFT=libft/libft.a

SRCS= src/ft_printf.c src/ft_reset_print.c src/ft_put.c src/ft_return.c\
src/ft_convert.c src/ft_utils.c

BONUS_SRCS= srcb/ft_calc_size_bonus.c srcb/ft_convert_bonus.c srcb/ft_dash_flag_bonus.c\
srcb/ft_flag_bonus.c srcb/ft_plus_flag_bonus.c srcb/ft_precision_flag_bonus.c\
srcb/ft_printf_bonus.c srcb/ft_put_bonus.c srcb/ft_reset_print_bonus.c\
srcb/ft_return_bonus.c srcb/ft_sharp_flag_bonus.c srcb/ft_space_flag_bonus.c\
srcb/ft_utils_bonus.c srcb/ft_width_flag_bonus.c srcb/ft_zero_flag_bonus.c

OBJS= $(SRCS:.c=.o)

BONUS_OBJS= $(BONUS_SRCS:.c=.o)

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus