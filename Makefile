NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES = includes
OBJECTS = object_files
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a
IFLAGS = -I$(INCLUDES) -I$(LIBFT)

PS_COMMON_SRCS = srcs/error/error_exit.c \
	srcs/parse/parse_args.c \
	srcs/parse/parse_utils.c \
	srcs/parse/parse_validate.c \
	srcs/ops/op_print.c \
	srcs/ops/op_push.c \
	srcs/ops/op_rev_rotate.c \
	srcs/ops/op_rotate.c \
	srcs/ops/op_swap.c \
	srcs/sort/sort_big.c \
	srcs/sort/sort_dispatch.c \
	srcs/sort/sort_small.c \
	srcs/sort/sort_small_2.c \
	srcs/sort/sort_small_3.c \
	srcs/sort/sort_small_4.c \
	srcs/sort/sort_small_5.c \
	srcs/sort/sort_utils.c \
	srcs/stack/stack_index.c \
	srcs/stack/stack_index_utils.c \
	srcs/stack/stack_new.c \
	srcs/stack/stack_node_new.c \
	srcs/stack/stack_pop_top.c \
	srcs/stack/stack_push_bottom.c \
	srcs/stack/stack_push_top.c \
	srcs/stack/stack_reverse_rotate.c \
	srcs/stack/stack_rotate.c \
	srcs/stack/stack_swap_top.c \
	srcs/state/state_free.c \
	srcs/state/state_new.c

PS_SRCS = srcs/main.c $(PS_COMMON_SRCS)

BONUS_SRCS = bonus/checker.c $(PS_COMMON_SRCS)

O_FILES = $(PS_SRCS:%.c=$(OBJECTS)/%.o)
BONUS_O_FILES = $(BONUS_SRCS:%.c=$(OBJECTS)/%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

$(NAME): $(O_FILES) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(O_FILES) $(LIBFT_A) -o $(NAME)
	@echo "$(NAME) is ready"

$(BONUS_NAME): $(BONUS_O_FILES) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(BONUS_O_FILES) $(LIBFT_A) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) is ready"

$(OBJECTS):
	@mkdir -p $(OBJECTS)

$(OBJECTS)/%.o: %.c $(INCLUDES)/push_swap.h | $(OBJECTS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -rf $(OBJECTS)
	@$(MAKE) clean -C $(LIBFT)
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME) a.out
	@$(MAKE) fclean -C $(LIBFT)
	@echo "All files were deleted"

re: fclean all

test: 
	@./push_swap

testleaks:
	@valgrind --leak-check=full --show-leak-kinds=all ./push_swap

norm:
	@norminette

.PHONY: all bonus clean fclean re
