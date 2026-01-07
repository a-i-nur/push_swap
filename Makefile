NAME = push_swap
CC = cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES = includes
SOURCES = srcs
OBJECTS = object_files
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a
IFLAGS = -I$(INCLUDES) -I$(LIBFT)

C_FILES = push_swap.c

O_FILES = $(addprefix $(OBJECTS)/,$(C_FILES:.c=.o))

all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

$(NAME): $(O_FILES) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(O_FILES) $(LIBFT_A) -o $(NAME)
	@echo "$(NAME) is ready"

$(OBJECTS):
	@mkdir -p $(OBJECTS)

$(OBJECTS)/%.o: $(SOURCES)/%.c $(INCLUDES)/push_swap.h | $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -rf $(OBJECTS)
	@$(MAKE) clean -C $(LIBFT)
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME) a.out
	@$(MAKE) fclean -C $(LIBFT)
	@echo "All files were deleted"

re: fclean all

test: 
	@./push_swap

testleaks:
	@valgrind --leak-check=full --show-leak-kinds=all ./push_swap

norm:
	@norminette

.PHONY: all clean fclean re
