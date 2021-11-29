#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_memcpy( void *destination, const void *source, size_t size );
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);
char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_min(size_t a, size_t b);
int     read_file(int fd, char **buffer, char **buffer_line, char **ligne);
char    *get_line(char **buffer_line, char **ligne);

#endif