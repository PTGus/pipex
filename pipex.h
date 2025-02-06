/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:32 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/06 16:02:47 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUF_SIZE 1024

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

// main //
int		main(int ac, char **av, char **env);

// parse //
void	check_args(char **av);
char	**parse_args(int ac, char **av);

#endif