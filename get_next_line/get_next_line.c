#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			k;

	k = 0;
	p = (unsigned char *) b;
	while (k != len)
	{
		p[k] = (unsigned char)c;
		k++;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = malloc(nmemb * size);
	if (p)
		ft_memset(p, 0, nmemb * size);
	return (p);
}

char	*return_ostatok(char *buf, char *ostatok, int rs, char **line)
{
	char	*tmp;

	if (rs == -2)
	{
		*line = ft_substr(ostatok, 0, ft_strchr(ostatok, '\n') - 1);
		tmp = ft_strdup(ostatok + ft_strchr(ostatok, '\n'));
		free(ostatok);
		return (tmp);
	}
	if (rs == -1)
	{
		ostatok = NULL;
		return (ostatok);
	}
	if (rs > 0)
	{
		buf[rs] = '\0';
		tmp = ft_strdup(ostatok);
		free(ostatok);
		ostatok = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
		return (ostatok);
	}
	return (NULL);
}

int	return_flag (char *buf, char *ostatok, int rs, char **line)
{
	if (rs < 0)
	{
		free(buf);
		free(ostatok);
		return (-1);
	}
	if (rs == 0)
	{
		*line = ft_substr(ostatok, 0, ft_strchr(ostatok, '\0'));
		free(ostatok);
		free(buf);
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ostatok;
	int			rs;
	int			flag;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (ostatok == NULL)
		ostatok = ft_calloc(1, 1);
	while (1)
	{
		if (ft_strchr(ostatok, '\n') != 0)
		{
			ostatok = return_ostatok(buf, ostatok, -2, line);
			return (1);
		}
		buf = malloc(BUFFER_SIZE + 1);
		rs = read(fd, buf, BUFFER_SIZE);
		flag = return_flag(buf, ostatok, rs, line);
		ostatok = return_ostatok(buf, ostatok, rs, line);
		if (rs == 0 || rs < 0)
			return (flag);
	}
}
