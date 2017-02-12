/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:59:14 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/12 15:59:15 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LU_LIBFT_H
# define LU_LIBFT_H

# include <string.h>
# include <inttypes.h>

int				lu_atoi(const char *nptr);
void			lu_bzero(void *s, size_t n);
int				lu_isalnum(int c);
int				lu_isalpha(int c);
int				lu_isascii(int c);
int				lu_isdigit(int c);
int				lu_isprint(int c);
char			*lu_itoa(int n);
void			*lu_memalloc(size_t size);
void			*lu_memccpy(void *dest, const void *src, int c, size_t n);
void			*lu_memchr(const void *s, int c, size_t n);
int				lu_memcmp(const void *s1, const void *s2, size_t n);
void			*lu_memcpy(void *dest, const void *src, size_t n);
void			lu_memdel(void **ap);
void			*lu_memmove(void *dest, const void *src, size_t n);
void			*lu_memset(void *s, int c, size_t n);
void			lu_putchar(char c);
void			lu_putchar_fd(char c, int fd);
void			lu_putendl(char const *s);
void			lu_putendl_fd(char const *s, int fd);
void			lu_putnbr(int n);
void			lu_putnbr_fd(int n, int fd);
void			lu_putstr(char const *s);
void			lu_putstr_fd(char const *s, int fd);
char			*lu_strcat(char *dest, char *src);
char			*lu_strchr(const char *s, int c);
void			lu_strclr(char *s);
int				lu_strcmp(const char *s1, const char *s2);
char			*lu_strcpy(char *dest, const char *src);
void			lu_strdel(char **as);
char			*lu_strdup(const char *s);
int				lu_strequ(char const *s1, char const *s2);
void			lu_striter(char *s, void (*f)(char *));
void			lu_striteri(char *s, void (*f)(unsigned int, char *));
char			*lu_strjoin(char const *s1, char const *s2);
size_t			lu_strlcat(char *dst, const char *src, size_t size);
size_t			lu_strlen(const char *s);
char			*lu_strmap(char const *s, char (*f)(char));
char			*lu_strmapi(char const *s, char (*f)(unsigned int, char));
char			*lu_strncat(char *dest, const char *src, size_t n);
int				lu_strncmp(const char *s1, const char *s2, size_t n);
char			*lu_strncpy(char *dest, const char *src, size_t n);
int				lu_strnequ(char const *s1, char const *s2, size_t n);
char			*lu_strnew(size_t size);
char			*lu_strnstr(const char *big, const char *little, size_t len);
char			*lu_strrchr(const char *s, int c);
char			**lu_strsplit(char const *s, char c);
char			*lu_strstr(const char *haystack, const char *needle);
char			*lu_strsub(char const *s, unsigned int start, size_t len);
char			*lu_strtrim(char const *s);
int				lu_tolower(int c);
int				lu_toupper(int c);

typedef	struct	s_listo
{
	void			*content;
	size_t			content_size;
	struct s_listo	*next;
}				t_listo;

t_listo			*lu_lstnew(void const *content, size_t content_size);
void			lu_lstdelone(t_listo **alst, void (*del)(void *, size_t));
void			lu_lstdel(t_listo **alst, void (*del)(void *, size_t));
void			lu_lstadd(t_listo **alst, t_listo *new);
void			lu_lstiter(t_listo *lst, void (*f)(t_listo *elem));
t_listo			*lu_lstmap(t_listo *lst, t_listo *(*f)(t_listo *elem));

int				lu_nb_words(const char *s, char c);
int				lu_isblank(int c);
int				lu_iscntrl(int c);
int				lu_isgraph(int c);
int				lu_islower(int c);
int				lu_isspace(int c);
int				lu_isupper(int c);
int				lu_isxdigit(int c);
char			*lu_intmaxtoa_base(intmax_t value, char base);
char			*lu_uintmaxtoa_base(uintmax_t value, unsigned char base);
char			*lu_itoa_base(int value, int base);
char			*lu_newstr(size_t size);
int				lu_str_is_alpha(char *str);
int				lu_str_is_lowercase(char *str);
int				lu_str_is_numeric(char *str);
int				lu_str_is_printable(char *str);
int				lu_str_is_uppercase(char *str);
char			*lu_strcapitalize(char *str);
int				lu_strcasecmp(const char *s1, const char *s2);
size_t			lu_strlcpy(char *dst, const char *src, size_t size);
char			*lu_strlowcase(char *str);
char			*lu_strndup(const char *s, size_t n);
char			*lu_strupcase(char *str);

#endif
