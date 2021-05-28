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



int error(char *buf, char *ostatok)
{
	free(buf);
	free(ostatok);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*ostatok;
	int			rs;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (ostatok == NULL)
		ostatok = ft_calloc(1, 1);
  while (1)
  {
    if (ft_strchr(ostatok, '\n') != 0)
    {
      *line = ft_substr(ostatok, 0, ft_strchr(ostatok, '\n') - 1);
	  tmp = ft_strdup(ostatok + ft_strchr(ostatok, '\n'));
	  free(ostatok);
      ostatok = tmp;
      return (1);
    }
    else
    {
      buf = malloc(BUFFER_SIZE + 1);
      rs = read(fd, buf, BUFFER_SIZE);
	  if (rs < 0)
		return(error(buf, ostatok));
      if (rs == 0)
      {
        *line = ft_substr(ostatok, 0, ft_strchr(ostatok, '\0'));
	  	free(ostatok);
		free(buf);
		ostatok = NULL;
        return (0);
      }
      buf[rs] = '\0';
	  tmp = ft_strdup(ostatok);
	  free(ostatok);
      ostatok = ft_strjoin(tmp, buf);
	  free(tmp);
	  free(buf);
    }
  }
}