/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:32 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/04 17:14:16 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

#endif