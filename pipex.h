/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:32 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/12 15:36:07 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUF_SIZE 1024

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

// main //
int		main(int ac, char **av, char **env);
void	run_parent(char **av, int *pipe_fd, char **env);
void	run_child(char **av, int *pipe_fd, char **env);
void	do_cmd(char *cmd, char **env);
void	error_handler(void);

// utils //
int		open_file(char *file, int in_out);
char	*ft_getenv(char *name, char **env);
char	*pather(char *cmd, char **env);
void	ft_free_split(char **str);

#endif