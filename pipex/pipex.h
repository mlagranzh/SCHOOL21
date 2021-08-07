#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
char	**utils_parse_filename(char **envp);
char	*parse_filename(char *command, char **envp);
void	child_process(char	**argv, char	**envp, int *fd);
void	parent_process(char	**argv, char	**envp, int *fd, int pid);
#endif
