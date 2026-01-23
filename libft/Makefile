CC = cc
FLAGS = -Wall -Wextra -Werror -I.
NAME = libft.a
HEADER = libft.h
OBJ_DIR = object_files
VPATH = . ft_printf get_next_line

LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FT_PRINTF_SRCS 	= ft_printf.c ft_get_arg_info.c ft_print_types.c ft_print_c_type.c \
ft_print_p_type.c ft_print_s_type.c ft_print_di_type.c \
ft_print_u_type.c ft_print_x_type.c ft_len_num_base.c \
ft_putnbr_base_fd.c ft_putchar_fd_ret.c ft_putstr_fd_ret.c \
ft_putnbr_fd_ret.c

GNL_SRCS = get_next_line.c get_next_line_utils.c get_next_line_mfd.c

SRCS = $(LIBFT_SRCS) $(addprefix ft_printf/,$(FT_PRINTF_SRCS)) \
	   $(addprefix get_next_line/,$(GNL_SRCS))
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^
	@echo "Libc functions, additional functions are ready"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ is ready"

clean:
	@rm -rf $(OBJ_DIR)
	@echo ".o files were deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "All files were deleted"

re: fclean all

.PHONY: all clean fclean re
