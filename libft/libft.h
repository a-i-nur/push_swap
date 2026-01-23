/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:34:38 by aakhmeto          #+#    #+#             */
/*   Updated: 2026/01/07 18:30:24 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
/*# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h> */

// LIBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int			ft_isalpha(int symbol);
int			ft_isdigit(int symbol);
int			ft_isalnum(int symbol);
int			ft_isascii(int symbol);
int			ft_isprint(int symbol);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *mem_area, int symbol, size_t num_bytes);
void		ft_bzero(void *mem_area, size_t num_bytes);
void		*ft_memcpy(void *dst_mem, const void *src_mem, size_t num_bytes);
void		*ft_memmove(void *dst_mem, const void *src_mem, size_t num_bytes);
size_t		ft_strlcpy(char *dst_str, const char *src_str, size_t dst_size);
size_t		ft_strlcat(char *dst_str, const char *src_str, size_t dst_size);
int			ft_toupper(int chrctr);
int			ft_tolower(int chrctr);
char		*ft_strchr(const char *str, int chrctr);
char		*ft_strrchr(const char *str, int chrctr);
int			ft_strncmp(const char *str1, const char *str2, size_t num);
void		*ft_memchr(const void *mem_area, int byte, size_t num_bytes);
int			ft_memcmp(const void *area1, const void *area2, size_t num_bytes);
char		*ft_strnstr(const char *big_str, const char *lit_str, size_t num);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count_obj, size_t size_per_obj);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PRINTF
typedef struct s_argument
{
	unsigned char	type;
	int				len;
}				t_argument;
int			ft_printf(const char *format, ...);
t_argument	ft_get_arg_info(const char *format, int index);
int			ft_print_types(va_list *arguments, t_argument arg_info);
int			ft_print_c_type(va_list *arguments);
int			ft_print_p_type(va_list *arguments);
int			ft_print_s_type(va_list *arguments);
int			ft_print_di_type(va_list *arguments);
int			ft_print_u_type(va_list *arguments);
int			ft_print_x_type(va_list *arguments, char type);
int			ft_len_num_base(unsigned long number, int base);
int			ft_putnbr_base_fd(unsigned long n,
				char *digits_base, int base, int fd);
int			ft_putchar_fd_ret(char c, int fd);
int			ft_putstr_fd_ret(char *s, int fd);
int			ft_putnbr_fd_ret(int n, int fd);

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_read_buffer
{
	char	read_text[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	size_t	index_tail;
	int		f_end_line;
}	t_read_buffer;
typedef struct s_ret_line
{
	char	*res;
	size_t	len;
	size_t	size;
}	t_ret_line;
char		*get_next_line(int fd);
int			ft_update_buf_info(t_read_buffer *buf, t_ret_line *line);
int			ft_create_line(t_read_buffer *buf, t_ret_line *line);
int			ft_check_read_text(t_read_buffer *buf, t_ret_line *line);
char		*get_next_line_mfd(int fd);
void		ft_set_zero_buf(t_read_buffer *buf);
void		ft_liberator(char *str);
int			ft_line_realloc(t_ret_line *line, size_t new_size);
int			ft_check_end_line(t_read_buffer *buf, t_ret_line *line, int index);
void		ft_set_zero_line(t_ret_line *line);

#endif
