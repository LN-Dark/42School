/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libft.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pcruz <pcruz@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/15 08:58:45 by pbranco-		  #+#	#+#			 */
/*   Updated: 2025/01/20 08:01:59 by pcruz			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_split
{
	char	**strs;
	char	*str;
	char	*seps;
	int		i;
	int		j;
	int		wcounter;
}	t_split;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_tolower(int i);
int		ft_toupper(int i);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isspace(int c);
int		ft_isdigitplussign(int i);
int		ft_isprint(int i);
int		ft_printf(const char *format, ...);
int		ft_printc(int c);
int		ft_printstr(char *str);
int		ft_put_hex(unsigned long nb, const char form);
int		ft_print_pointer(unsigned long pointer);
int		ft_printnbr(int nb);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int nb, const char form);
int		ft_strlen(const char *str);
int		ft_strichr_gnl(const char *s, int c);
int		ft_strnlen_gnl(const char *str, char c, int type);
int		ft_strncmp(const char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_arraylen(char **array);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_uitoa(unsigned int n);
char	*ft_strdup_free(char *s);
char	*ft_strchr(const char *s, int i);
char	**ft_split(char const *str, char c);
char	**ft_split_wdelim(char *str, char *sep);
char	*ft_read_gnl(int fd, char *temp);
char	*ft_maketemp_gnl(char *temp);
char	*get_next_line(int fd);
char	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strndup_gnl(const char *s, int lenght);
char	*ft_strdup_gnl(char *src);
char	*ft_strncat(char *dst, const char *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strcjoin(char *str, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char *s1, char *set);
char	*ft_strtrim_free(char *s1, char *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncpy(char *dst, const char *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strstr(const char *haystack, const char *needle);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_gnl(char **temp);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

int		ft_lstsize(t_list *lst);

long	ft_atol(const char *str);

void	ft_free(char **strs);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*ft_strndup(char *s, size_t n);
char	*ft_strndup_free(char *s, size_t n);

#endif
