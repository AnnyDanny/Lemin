/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:55:08 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/15 14:55:09 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# define PLUS 0
# define MINUS 1
# define HASH 2
# define SPACE 3
# define ZERO 4
# define H 5
# define L 6
# define HH 7
# define LL 8
# define Z 9
# define J 10
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_struct
{
	char			sp;
	int				flags[11];
	long long int	width;
	long long int	p;
	char			*str1;
	int				l1;
	int				i;
	int				l2;
	wchar_t			*s2;
}					t_struct;

typedef struct		s_arg
{
	char			*f;
	int				i;
}					t_arg;

typedef struct		s_get
{
	char			*t;
	char			*d;
	int				ret;
	char			*buf;
	char			*tmp;
	t_list			*buf2;
}					t_get;

int					get_next_line(const int fd, char **line);
int					ft_printf(char *format, ...);
int					ft_strlen_int(int num);
int					check_types(t_struct *s, va_list arg, int count);
void				check_width_prec(int i, char *format, t_struct *s);
void				check_flags1(int *i, char *format, t_struct *s);
void				check_flags2(int *i, char *format, t_struct *s);
void				check_flags3(int *i, char *format, t_struct *s);
void				check_flags4(int *i, char *format, t_struct *s);
void				check_flags5(int *i, char *format, t_struct *s);
int					print_nulls(t_struct *s, int count);
int					print_spaces(t_struct *s, int count);
int					check_space(t_struct *s);
void				check_flags(int *i, char *format, t_struct *s);
long long			check_flags_d(long long d, t_struct *s);
int					check_plus_minus(long long d, int count, t_struct *s);
long long			check_all_d_i_bd(t_struct *s, va_list arg, int count);
int					print_space(t_struct *s, int d, int count);
int					print_nulls_d(t_struct *s, int len, int count, int d);
int					print_spaces_d(t_struct *s, int len, int count, int d);
int					print_spaces_c(t_struct *s, int count);
int					check_flags_c(t_struct *s);
int					print_nulls_c(t_struct *s, int count);
int					print_spaces_s(t_struct *s, int count, int len);
int					print_nulls_s(t_struct *s, int count, int len);
int					print_nulls_null(t_struct *s, int count);
int					print_type_s(t_struct *s, va_list arg, int count);
int					print_type_c(t_struct *s, va_list arg, int count);
int					pr_sp_u_s(t_struct *s, int len, int count, char c);
size_t				num_bytes(wchar_t *str);
int					check_prec_bs(unsigned int c);
void				no_minus(t_struct *s, int *count);
void				yes_minus(t_struct *s, int *count);
int					pr_t_u_s(t_struct *s, va_list arg, int count);
int					ft_3_byte(unsigned int c);
int					ft_2_byte(unsigned int c);
int					ft_4_byte(unsigned int c);
int					print_type_uni_c(unsigned int c, int count);
unsigned long long	check_flags_u(unsigned long long u, t_struct *s);
int					print_spaces_o(t_struct *s, int len, int count);
int					print_nulls_o(t_struct *s, int len, int count);
int					check_null_o(unsigned long long nbr);
unsigned long long	check_flags_o(unsigned long long o, t_struct *s);
int					ft_hex_len(unsigned long long x, int y);
void				hexa(unsigned long long nbr, int len, char *res);
int					check_hash_x(unsigned long long x, t_struct *s, int count);
int					check_hash(unsigned long long x, t_struct *s, int count);
int					print_spaces_x(t_struct *s, int len, int count);
int					print_nulls_x(t_struct *s, int len, int count, int x);
unsigned long long	check_flags_x(unsigned long long x, t_struct *s);
int					s_p(t_struct *s, int len, int count, unsigned long long p);
int					p_z(t_struct *s, int len, int count, unsigned long long p);
int					print_hexa_x_p(unsigned long long nbr);
int					print_hexa_p(t_struct *s, va_list arg, int count);
int					print_type_x(t_struct *s, va_list arg, int count);
int					print_hexa_uni_x(unsigned long long int nbr);
int					print_type_uni_x(t_struct *s, va_list arg, int count);
void				clear_struct(t_struct *s);
int					ft_strlen_int(int num);
int					check_types(t_struct *s, va_list arg, int count);
int					ch_f(char *format, t_struct *s, va_list arg, int count);
int					check_plus_minus(long long d, int count, t_struct *s);
int					print_type_o(t_struct *s, va_list arg, int count);
int					print_type_u(t_struct *s, va_list arg, int count);
void				check_width_prec(int i, char *format, t_struct *s);
int					print_spaces_uni_s(t_struct *s, int len, int count, char c);
int					print_type_uni_s(t_struct *s, va_list arg, int count);
void				ft_print_numbers(void);
void				ft_is_negative(int n);
int					ft_countstrclen(char *str, int c);
void				ft_swap(int *a, int *b);
int					ft_sqrt(int b);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putendl(char const *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *sbig, const char *little, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *dest, const char *app, size_t n);
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void(*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strenqu(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *str);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *str, int ch);
char				*ft_strcat(char *dest, const char *app);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl_fd(char const *str, int fd);
void				*ft_memset(void *dest, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_isprint(int ch);
int					ft_isdigit(int ch);
int					ft_isascii(int ch);
int					ft_isalpha(int c);
int					ft_isalnum(int ch);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_itoa(long long n);

#endif
