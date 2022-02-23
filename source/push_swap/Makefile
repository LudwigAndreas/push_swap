PROJ_NAME		:=	push_swap
MAIN_DIR		:= ../../
NAME			:= $(addprefix $(MAIN_DIR), $(PROJ_NAME))
CFLAGS			:= -Wall -Wextra -Werror -c
OFLAGS			:= -Wall -Wextra -Werror -o
SRC_DIR			:= srcs/
OBJ_DIR			:= ../../objects/push_swap_objs/
SRCS_FILES		:=	list.c\
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
					get_stack_a.c\
					largest_seq.c\
					tools.c\
					do_rotate.c\
					sort_one_stack.c
OBJS_FILES		:= $(SRCS_FILES:.c=.o)
SRCS			:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))
RM				:= rm -rf
LIBFTDIR_PATH	:= ../../libft/
HEADER			:= includes/push_swap.h

.PHONY: all clean fclean re

all: obj $(NAME)

obj: $(SRCS)
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(CFLAGS) $< -o $@ -include $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	make -C $(LIBFTDIR_PATH)
	gcc $(OFLAGS) $(NAME) $(OBJS) $(LIBFTDIR_PATH)libft.a -include $(LIBFTDIR_PATH)libft.h -include $(HEADER)

clean:
	make clean -C $(LIBFTDIR_PATH)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFTDIR_PATH)
	rm -f $(NAME)

re: fclean all
