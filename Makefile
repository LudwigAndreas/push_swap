NAME		:= push_swap
CFLAGS		:= -Wall -Wextra -Werror -c
OFLAGS		:= -Wall -Wextra -Werror -o
SRC_DIR		:= ./srcs/
OBJ_DIR		:= ./objs/
SRCS_FILES	:=	list.c\
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
				sort.c\
				print_data.c\
				get_stack_a.c\
				largest_seq.c\
				tools.c\
				do_rotate.c
OBJS_FILES	:= $(SRCS_FILES:.c=.o)
SRCS		:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS		:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))
RM			:= rm -rf
HEADER		:= includes/push_swap.h

.PHONY: all clean fclean re

all: obj $(NAME)

obj: $(SRCS)
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) $< -o $@ -include $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	make re -C libft/
	gcc $(OFLAGS) $(NAME) $(OBJS) libft/libft.a -include /libft/libft.h -include $(HEADER)

run: ./$(NAME)
	valgrind --leak-check=full --show-leak-kinds=all  --track-origins=yes --verbose  --log-file=valgrind-out.txt ./$(NAME) $(ARGS)

clean:
	make clean -C libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
