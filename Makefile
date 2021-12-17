NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_bonus.c ft_putstr.c ft_putunbr.c ft_putptr.c ft_puthexa.c ft_sharp.c

OBJECTS = $(SRC:.c=.o)

INCLUDES = ft_printf.h\

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	ar rcs $(NAME) $(OBJECTS)

bonus :$(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_bonus)

fclean:clean
	rm -rf $(NAME)

re: fclean all

