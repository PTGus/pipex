/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:23 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/06 12:04:05 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	int		pipe_fd1[2];
	int		pipe_fd2[2];
	pid_t	pid;
	if (ac < 5)
	{
		ft_putstr_fd("Insufficient arguments.\n", 2);
		return (1);
	}
	check_args(av);
	
}


// int main(int ac, char **av, char **env)
// {
// 	int		pipe_fd[2];
// 	pid_t	pid;
// 	char	buffer[1024];
// 	int		bytes_read;
// 	int		output_fd;

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("Pipe");
// 		return(1);
// 	}
// 	pid = fork();
// 	if (pid < -1)
// 	{
// 		perror("Fork");
// 		return(1);
// 	}
// 	else if (pid == 0)
// 	{
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(pipe_fd[1]);
// 		char *argv[] = {"/bin/cat", "input.txt", NULL};
// 		execve("/bin/cat", argv, NULL);
// 		if (execve("/bin/cat", argv, NULL) == -1)
// 		{
// 			perror("execve");
// 			return (1);
// 		}
// 	}
// 	else
// 	{
// 		close(pipe_fd[1]);
// 		output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (output_fd < 0)
// 		{
//             perror("open");
//             return 1;
//         }
// 		while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
// 		{
//             write(output_fd, buffer, bytes_read);
//         }
// 		close(pipe_fd[0]);
// 		close(output_fd);
// 		wait(NULL);
// 	}
// 	return (0);
// }
