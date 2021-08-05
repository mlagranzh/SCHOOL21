#include "pipex.h"

void free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*parse_filename(char *command, char **envp)
{
	int		i;
	char	**parse_1;
	char	**parse_2;
	char	*parse_3;
	char	*parse_4;

	i = 1;
	while (command[i - 1] != '\0')
	{
		if (command[i] == '/' && command[i + 1] != '/')
			return (command);
		i++;
	}
	while ((*envp)[0] != 'P' || (*envp)[1] != 'A' || \
					(*envp)[2] != 'T' || (*envp)[3] != 'H' || (*envp)[4] != '=')
		envp++;
	parse_1 = ft_split(*envp, '=');
	parse_2 = ft_split(parse_1[1], ':');
	free_array(parse_1);
	i = 0;
	while (1)
	{
		parse_3 = ft_strjoin(parse_2[i], "/");
		parse_4 = ft_strjoin(parse_3, command);
		free(parse_3);
		i++;
		if (access(parse_4, X_OK) != -1)
		{
			free_array(parse_2);
			return (parse_4);
		}
		free(parse_4);
	}
}

void	child_process(char	**argv, char	**envp, int *fd)
{
	int		file1;
	int		rs;
	char	*filename;
	char	**command;

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
	filename = parse_filename(ft_split(argv[2], ' ')[0], envp);
	command = ft_split(argv[2], ' ');
	rs = execve(filename, command, envp);
	if (rs == -1)
	{
		perror("ERROR CHILD");
		exit(1);
	}
}

void	parent_process(char	**argv, char	**envp, int *fd)
{
	int		file2;
	int		rs;
	char	*filename;
	char	**command;

	file2 = open(argv[4], O_WRONLY);
	if (file2 == -1)
	{
		perror("ERROR FILE2");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(file2, STDOUT_FILENO);
	char **tmp = ft_split(argv[3], ' ');
	filename = parse_filename(tmp[0], envp);
	free_array(tmp);
	command = ft_split(argv[3], ' ');
	rs = execve(filename, command, envp);
	free_array(command);
	free(filename);
	if (rs == -1)
	{
		perror("ERROR PARENT");
		exit(1);
	}
}

int	main(int	argc, char	**argv, char	**envp)
{
	int	fd[2];
	int pid;

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
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	return (0);
}
