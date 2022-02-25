PROJ_NAME		:=	checker
MAIN_DIR		:= ../../
NAME			:= $(addprefix $(MAIN_DIR), $(PROJ_NAME))
CFLAGS			:= -Wall -Wextra -Werror -c
OFLAGS			:= -Wall -Wextra -Werror -o
SRC_DIR			:= srcs/
OBJ_DIR			:= ../../objects/checker_objs/
SRCS_FILES		:=	checker.c\
					do_command.c\
					ft_readline.c\
					get_indexes.c\
					is_sorted.c\
					list.c\
					main.c\
					parse.c\
					push.c\
					quick_sort.c\
					reverse_rotate.c\
					rotate.c\
					swap.c\
					validator.c
OBJS_FILES		:= $(SRCS_FILES:.c=.o)
SRCS			:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))
RM				:= rm -rf
LIBFTDIR_PATH	:= ../../libft/
HEADER			:= includes/checker.h

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
