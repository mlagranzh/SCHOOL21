#include "pipex.h"

char	**utils_parse_filename(char **envp)
{
	char	**parse_1;
	char	**parse_2;

	while ((*envp)[0] != 'P' || (*envp)[1] != 'A' || \
					(*envp)[2] != 'T' || (*envp)[3] != 'H' || (*envp)[4] != '=')
		envp++;
	parse_1 = ft_split(*envp, '=');
	parse_2 = ft_split(parse_1[1], ':');
	parse_1 = ft_malloc_free(parse_1);
	return (parse_2);
}

char	*parse_filename(char *command, char **envp)
{
	int		i;
	char	**parse_1;
	char	*parse_2;
	char	*parse_3;

	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
		return (command);
	parse_1 = utils_parse_filename(envp);
	i = 0;
	while (1)
	{
		parse_2 = ft_strjoin(parse_1[(i++)], "/");
		parse_3 = ft_strjoin(parse_2, command);
		if (access(parse_3, X_OK) != -1)
		{
			parse_1 = ft_malloc_free(parse_1);
			return (parse_3);
		}
		free(parse_3);
		if (parse_1[i] == NULL)
		{
			parse_1 = ft_malloc_free(parse_1);
			return (NULL);
		}
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

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
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
