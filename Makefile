NAME := push_swap
CFLAGS := -Wall -Wextra -Werror -c
OFLAGS := -Wall -Wextra -Werror -o
SRCS := list.c\
		main.c\
		parse.c\
		validator.c\
		is_sorted.c\
		get_indexes.c\
		quick_sort.c\
		swap.c\
		push.c\
		rotate.c\
		reverse_rotate.c\
		sort.c
OBJS := $(SRCS:.c=.o)
RM := rm -rf
HEADER := push_swap.h

.PHONY: all clean fclean re

%.o: %.c
	gcc $(CFLAGS) $< -o $@ -include $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	make re -C libft/
	gcc $(OFLAGS) $(NAME) $(OBJS) libft/libft.a -include /libft/libft.h

all: $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
