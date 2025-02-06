/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:51:07 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/06 11:57:11 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_args(char **av)
{
	char	*tmp;

	if (open(av[1], O_RDONLY) == -1)
	{
		perror("File_1");
		exit (1);
	}
	tmp = ft_strjoin("/bin/", av[2]);
	if (access(tmp, X_OK) == -1)
	{
		perror("CMD_1");
		free(tmp);
		exit (1);
	}
	free(tmp);
	tmp = ft_strjoin("/bin/", av[3]);
	if (access(tmp, X_OK) == -1)
	{
		perror("CMD_2");
		free(tmp);
		exit (1);
	}
	free(tmp);
}