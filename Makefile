PUSH_SWAP		:= push_swap
CHECKER			:= checker
OBJ_DIR			:= objects/
CH_DIR			:= source/checker/
PS_DIR			:= source/push_swap/

.PHONY: all clean fclean re

all: $(PUSH_SWAP)

bonus: $(CHECKER)

obj:
	mkdir -p $(OBJ_DIR)

$(CHECKER): obj
	make -C $(CH_DIR)

$(PUSH_SWAP): obj
	make -C $(PS_DIR)

clean:
	make clean -C $(CH_DIR)
	make clean -C $(PS_DIR)
	rm -rf $(OBJ_DIR)

fclean:
	make fclean -C $(CH_DIR)
	make fclean -C $(PS_DIR)
	rm -rf $(OBJ_DIR)

re:
	rm -rf $(OBJ_DIR)
	make re -C $(CH_DIR)
	make re -C $(PS_DIR)

