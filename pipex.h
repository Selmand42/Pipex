/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:08:31 by muhademi          #+#    #+#             */
/*   Updated: 2024/03/27 15:12:17 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	process1(char **argv, int *fd, char **env);
void	run_exec(char *command, char **env);
void	process2(char **argv, int *fd, char **env);
char	*get_path(char **env);
void	error(void);
char	*get_command_path(char **env, char *command);
void	close_fd(int *fd);

#endif
