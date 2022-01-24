NAME := push_swap
CFLAGS := -Wall -Wextra -Werror -c
OFLAGS := -Wall -Wextra -Werror -o
SRCS := list.c\
		main.c\
		moves.c\
		parse.c\
		validator.c
OBJS := $(SRCS:.c=.o)
RM := rm -rf
HEADER := push_swap.h

.PHONY: all clean fclean re

%.o: %.c
	gcc $(CFLAGS) $< -o $@ -include $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	make re -C libftprintf/
	gcc $(OFLAGS) $(NAME) $(OBJS) libftprintf/libftprintf.a

all: $(NAME)

clean:
	make clean -C libftprintf/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libftprintf/
	rm -rf $(NAME)