/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:00:48 by ccarnot           #+#    #+#             */
/*   Updated: 2023/12/07 10:49:36 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

/* Libft */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				n;
}		t_list;

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*g)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Get next line */
char		*get_next_line(int fd, int free_status);
char		*ft_read(int fd, char *buffer);
char		*ft_bufupdate(char *buffer, char *new_buf);
char		*ft_line(char *buffer);
char		*ft_bufremain(char *buffer);

/* Ft_printf */
int			ft_print_char(va_list ap);
int			ft_print_str(va_list ap);
int			ft_putnbr(int nb);
int			ft_print_int(va_list ap);
int			ft_putnbr_u(unsigned int n);
int			ft_print_uint(va_list ap);
int			ft_putnbr_hexa(unsigned int n, char *base);
int			ft_print_hexa_low(va_list ap);
int			ft_print_hexa_up(va_list ap);
int			ft_print_pointer(va_list ap);
int			ft_readarg(va_list ap, char c);
int			ft_printf(const char *s, ...);
int			ft_putnbr_hexa_ulint(unsigned long int n, char *base);
void		ft_putchar(char c);

#endif
