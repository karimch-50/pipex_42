/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:15:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:45:50 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	get_commands(t_pipex *pipex)
{
	int	exit_satus1;
	int	exit_satus2;
	int	i;

	i = 2;
	if (pipex->is_here_dock)
		i = 3;
	exit_satus1 = ((exit_satus2 = 0), 0);
	if (pipex->cmd_id == pipex->cmd_num - 1)
		exit_satus1 = ((exit_satus2 = 126), 127);
	if (pipex->cmd_args)
		free_double_ptr(pipex->cmd_args);
	if (pipex->valid_path)
		free(pipex->valid_path);
	pipex->cmd_args = get_command_args(pipex->argv[pipex->cmd_id + i]);
	pipex->valid_path = valid_command_path(pipex->paths, pipex->cmd_args[0]);
	if (!pipex->valid_path)
		print_error(ECNF, pipex->cmd_args[0], exit_satus1);
	if (pipex->valid_path && access(pipex->valid_path, X_OK))
		print_error(EPD, pipex->cmd_args[0], exit_satus2);
}
