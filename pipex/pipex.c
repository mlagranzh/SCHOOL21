#include "pipex.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void delay(double dly){
    /* save start time */
    const time_t start = time(NULL);

    time_t current;
    do{
        /* get current time */
        time(&current);

        /* break loop when the requested number of seconds have elapsed */
    }while(difftime(current, start) < dly);
}

char	*parse_filename(char *command, char **envp)
{
	int		i;
	char	**parse_1;
	char	**parse_2;
	char	*parse_3;
	char	*parse_4;

	i = 1;
	while (command[(i++) - 1] != '\0')
		if (command[i] == '/' && command[i + 1] != '/')
			return (command);
	while ((*envp)[0] != 'P' || (*envp)[1] != 'A' || \
					(*envp)[2] != 'T' || (*envp)[3] != 'H' || (*envp)[4] != '=')
		envp++;
	parse_1 = ft_split(*envp, '=');
	parse_2 = ft_split(parse_1[1], ':');
	parse_1 = ft_malloc_free(parse_1);
	i = 0;
	while (1)
	{
		parse_3 = ft_strjoin(parse_2[i], "/");
		parse_4 = ft_strjoin(parse_3, command);
		free(parse_3);
		i++;
		if (access(parse_4, X_OK) != -1)
		{
			parse_2 = ft_malloc_free(parse_2);
			return (parse_4);
		}
		free(parse_4);
	}
}

void	child_process(char	**argv, char	**envp, int *fd)
{
	int		file1;
	char	*filename;
	char	**command;
	char	**tmp;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		perror("ERROR FILE1");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(file1, STDIN_FILENO);
	tmp = ft_split(argv[2], ' ');
	filename = parse_filename(tmp[0], envp);
	tmp = ft_malloc_free(tmp);
	command = ft_split(argv[2], ' ');
	if (execve(filename, command, envp) == -1)
	{
		perror("ERROR CHILD");
		exit(1);
	}
}

void	parent_process(char	**argv, char	**envp, int *fd, int pid)
{
	int		file2;
	char	*filename;
	char	**command;
	char	**tmp;

	file2 = open(argv[4], O_WRONLY);
	waitpid(pid, NULL, 0);
	if (file2 == -1)
	{
		perror("ERROR FILE2");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(file2, STDOUT_FILENO);
	tmp = ft_split(argv[3], ' ');
	filename = parse_filename(tmp[0], envp);
	tmp = ft_malloc_free(tmp);
	command = ft_split(argv[3], ' ');
	delay(10);
	if (execve(filename, command, envp) == -1)
	{
		perror("ERROR PARENT");
		exit(1);
	}
}

int	main(int	argc, char	**argv, char	**envp)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
	{
		write(2, "ONLY 4 ARG\n", 11);
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("ERROR PIPE");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("ERROR PID");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, envp, fd);
	else
		parent_process(argv, envp, fd, pid);
	return (0);
}
