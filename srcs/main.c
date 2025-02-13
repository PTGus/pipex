/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:23 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/13 15:04:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_parent(char **av, int *pipe_fd, char **env);
void	run_child(char **av, int *pipe_fd, char **env);
void	do_cmd(char *cmd, char **env);
void	error_handler(void);

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		error_handler();
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		run_child(av, pipe_fd, env);
	else if (pid > 0)
		run_parent(av, pipe_fd, env);
	return (0);
}

void	do_cmd(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = pather(split_cmd[0], env);
	if (!path)
	{
		ft_free_split(split_cmd);
		perror("path resolution failed");
		exit(1);
	}
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_split(split_cmd);
		free(path);
		exit(1);
	}
	ft_free_split(split_cmd);
	free(path);
}

void	run_parent(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1); // Open and truncate file2 before executing cmd2
	if (fd == -1)
	{
		perror("open failed");
		exit(1);
	}
	close(pipe_fd[1]); // Close the write end of the pipe in the parent
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 for STDIN failed");
		exit(1);
	}
	close(pipe_fd[0]); // Close the read end of the pipe after duplicating
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 for STDOUT failed");
		exit(1);
	}
	close(fd); // Close the file descriptor after duplicating
	do_cmd(av[3], env);
}

void	run_child(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	if (fd == -1)
	{
		perror("open failed");
		exit(1);
	}
	close(pipe_fd[0]); // Close the read end of the pipe in the child
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 for STDOUT failed");
		close(pipe_fd[1]); // Ensure the write end of the pipe is closed
		close(fd); // Ensure the file descriptor is closed
		exit(1);
	}
	close(pipe_fd[1]); // Close the write end of the pipe after duplicating
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2 for STDIN failed");
		close(fd); // Ensure the file descriptor is closed
		exit(1);
	}
	close(fd); // Close the file descriptor after duplicating
	do_cmd(av[2], env);
}

void	error_handler(void)
{
	ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
	exit (0);
}
