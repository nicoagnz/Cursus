
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(s1, str);
	ft_strcpy(s2,(str + ft_strlen(s1)));
	free (s1);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str = c)
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_strcpy(char *str, char *dst)
{
	int	len = 0;

	while (str[len])
	{
		dst[len] = str[len];
		len++;
	}
	dst[len] = '\0';
}

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		len ++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dst;

	dst = malloc(sizeof(char) * ft_strlen(str));
	if (!dst)
		return (NULL);
	ft_strcpy(str, dst);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line;
	int			bytes = 0;
	int			to_copy = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	while (!(new_line = ft_strchr(line, '\n')) && (bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer(bytes) = '\0'
		line = ft_strjoin(line, buffer);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (new_line != NULL)
	{
		to_copy = new_line - line + 1;
		ft_strcpy(new_line + 1, buffer);
	}
	else
	{
		to_copy = ft_strlen(line);
		buffer[0] = NULL;
	}
	line[to_copy] = '\0';
	return (line);
}
