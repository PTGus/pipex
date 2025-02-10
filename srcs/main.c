/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:23 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/10 14:33:31 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* int main(int ac, char **av, char **env)
{
	int		pipe_fd1[2];
	int		pipe_fd2[2];
	int		bytes;
	char	*buf;
	char	**cmd1;
	char	**cmd2;
	pid_t	pid1;
	pid_t	pid2;

	if (ac < 5)
	{
		ft_putstr_fd("Insufficient arguments.\n", 2);
		return (1);
	}
	check_args(av);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork");
		return (1);
	}
	else if (pid1 == 0)
	{
		pipe(pipe_fd1);
		close(pipe_fd1[0]);
		dup2(pipe_fd1[1], STDOUT_FILENO);
		close(pipe_fd1[1]);
		cmd1 = parse_args(av[1], av[2]);
		if (execve(cmd1[0], cmd1, env) == -1)
		{
			perror("Execve");
			return (1);
		}
	}
	else
	{
		pid2 = fork();
		if (pid2 < 0)
		{
			perror("Fork pid2");
			return (1);
		}
		else if (pid2 == 0)
		{
			close(pipe_fd1[1]);
			dup2(pipe_fd1[0],STDIN_FILENO);
			close(pipe_fd1[0]);
			pipe(pipe_fd2);
			if (pipe_fd2 < 0)
			{
				perror("Pipe2");
				return (1);
			}
			close(pipe_fd2[0]);
			dup2(pipe_fd2[1], STDOUT_FILENO);
			close(pipe_fd2[1]);
			cmd2 = parse_args(av);
		}
	}
} */

int	main()
{
	printf("ola");
}

// int main(int ac, char **av, char **env)
// {
// 	int pipe_fd1[2];
// 	int file_fd;
// 	char *buf;
// 	int bytes;
// 	pid_t pid;
// 	char **cmd1;

// 	if (pipe(pipe_fd1) < 0)
// 	{
// 		perror("pipe");
// 		return 1;
// 	}
// 	if (ac < 5)
// 	{
// 		ft_putstr_fd("Insufficient arguments.\n", 2);
// 		return 1;
// 	}
// 	check_args(av);
// 	cmd1 = parse_args(ac, av[1], av[2]);
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		return 1;
// 	}
// 	if (pid == 0)
// 	{
// 		int k = 0;
// 		while (cmd1[k])
// 		{
// 			printf("%s\n", cmd1[k]);
// 			k++;
// 		}
// 		close(pipe_fd1[0]);
// 		dup2(pipe_fd1[1], STDOUT_FILENO);
// 		close(pipe_fd1[1]);
// 		execve(cmd1[0], cmd1, env);
// 		perror("execve");
// 		return 1;
// 	}
// 	else
// 	{
// 		buf = malloc(sizeof(char) * (BUF_SIZE + 1));
// 		if (buf == NULL)
// 		{
// 			perror("malloc");
// 			return 1;
// 		}
// 		close(pipe_fd1[1]);
// 		file_fd = open("output.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
// 		if (file_fd == -1)
// 		{
// 			perror("open");
// 			free(buf);
// 			return 1;
// 		}
// 		bytes = 1;
// 		char *str = malloc(sizeof(char));
// 		if (str == NULL)
// 		{
// 			perror("malloc");
// 			free(buf);
// 			close(pipe_fd1[0]);
// 			close(file_fd);
// 			return 1;
// 		}
// 		str[0] = '\0';
// 		int r_amm = 0;
// 		while (bytes > 0)
// 		{
// 			bytes = read(pipe_fd1[0], buf, BUF_SIZE);
// 			if (bytes < 0)
// 			{
// 				perror("read");
// 				free(buf);
// 				free(str);
// 				close(pipe_fd1[0]);
// 				close(file_fd);
// 				return 1;
// 			}
// 			buf[bytes] = '\0';
// 			r_amm += bytes;
// 			str = ft_strjoin(str, buf);
// 			if (!str)
// 			{
// 				perror("ft_strjoin");
// 				free(buf);
// 				close(pipe_fd1[0]);
// 				close(file_fd);
// 				return 1;
// 			}
// 		}
// 		printf("%s\n", str);
// 		write(file_fd, str, r_amm);
// 		free(buf);
// 		free(str);
// 		close(pipe_fd1[0]);
// 		close(file_fd);
// 		wait(NULL);
// 	}
// 	return 0;
// }
