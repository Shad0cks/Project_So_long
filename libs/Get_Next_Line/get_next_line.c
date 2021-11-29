#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*cped;
	int	i;

	cped = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cped == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cped[i] = src[i];
		i++;
	}
	cped[i] = '\0';
	return (cped);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char    *get_line(char **buffer_line, char **ligne)
{
    int index;
    char *temp;

    temp = *buffer_line;
    index = 0;
    while ((*buffer_line)[index] != '\n' && (*buffer_line)[index] != '\0')
        index++;
    if (ft_strchr(*buffer_line, '\n'))
    {
        *ligne = ft_substr(*buffer_line, 0, index + 1);
        *buffer_line = ft_strdup(*buffer_line + index + 1);
    }
    else
    {
        *ligne = ft_strdup(temp);
        *buffer_line = NULL;
    }
    free(temp);
    return (*ligne);
}

int read_file(int fd, char **buffer, char **buffer_line, char **ligne)
{
    char *temp;
    int ret;

    ret = 1;
    
    while(ret > 0 && !ft_strchr(*buffer_line, '\n'))
    {
        ret = read(fd, *buffer, BUFFER_SIZE);
        (*buffer)[ret] = '\0';
        temp = *buffer_line;
        *buffer_line = ft_strjoin(*buffer_line, *buffer);
        free(temp);
    }
    free(*buffer);
    get_line(buffer_line, ligne);
    return (ret);
}

char *get_next_line(int fd)
{
    char    *buffer;
    static char *buffer_line = NULL;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *) malloc((BUFFER_SIZE + 1));
    if (buffer == NULL)
        return NULL;
    if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
    buffer_line == NULL ? buffer_line =  ft_strdup("") : NULL;
    if (read_file(fd, &buffer, &buffer_line, &line) == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
    return (line);
}
