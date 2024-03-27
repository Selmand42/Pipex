/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:50:27 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/27 14:58:49 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_exec(char *command, char **env)
{
	char	*path;
	char	**commands;

	commands = ft_split(command, ' ');
	path = get_command_path(env, commands[0]);
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd(commands[0], 2);
		ft_putendl_fd(": There is no such command", 2);
		exit(EXIT_FAILURE);
	}
	execve(path, commands, env);
}

void	process1(char **argv, int *fd, char **env)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(file1);
	close_fd(fd);
	run_exec(argv[2], env);
}

void	process2(char **argv, int *fd, char **env)
{
	int	file2;

	file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (file2 == -1)
	{
		ft_putstr_fd(argv[4], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(EXIT_FAILURE);
	}
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(file2);
	close_fd(fd);
	run_exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		error();
		return (0);
	}
	pipe(fd);
	pid = fork();
	if (pid == 0)
		process1(argv, fd, env);
	else
	{
		wait(NULL);
		pid = fork();
		if (pid == 0)
			process2(argv, fd, env);
		else
			close_fd(fd);
	}
}
