/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:11 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/27 15:14:35 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	error(void)
{
	write(2, "Error\n", 6);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 5))
		{
			path = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	return (path);
}

char	*get_command_path(char **env, char *command)
{
	int		i;
	char	*path;
	char	**paths;
	char	*address;

	i = 0;
	path = get_path(env);
	paths = ft_split(path, ':');
	free(path);
	path = 0;
	command = ft_strjoin("/", command);
	while (paths[i])
	{
		address = ft_strjoin(paths[i], command);
		if (access(address, F_OK | X_OK) == 0)
			path = address;
		i++;
	}
	free(command);
	free(address);
	return (path);
}
