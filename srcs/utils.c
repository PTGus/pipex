/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:53:13 by gumendes          #+#    #+#             */
/*   Updated: 2025/02/13 13:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	open_file(char *file, int in_out)
{
	int	fd;

	fd = -1;
	if (in_out == 0)
	{
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
		{
			perror("error opening file1");
			exit(1);
		}
	}
	else if (in_out == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
		{
			perror("error opening/creating file2");
			exit(1);
		}
	}
	return (fd);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*pather(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**all_paths;
	char	*path_part;
	char	**split_cmds;

	all_paths = ft_split(ft_getenv("PATH", env), ':');
	split_cmds = ft_split(cmd, ' ');
	i = -1;
	while (all_paths[++i])
	{
		path_part = ft_strjoin(all_paths[i], "/");
		exec = ft_strjoin(path_part, split_cmds[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_split(split_cmds);
			ft_free_split(all_paths);
			return (exec);
		}
		free(exec);
	}
	ft_free_split(split_cmds);
	ft_free_split(all_paths);
	return (cmd);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
