/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:45:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 16:41:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	close_pipes_for_child(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < (pipex->cmd_num - 1) * 2)
	{
		if (pipex->cmd_id == 0 && i < 2)
			i += 2;
		else if (pipex->cmd_id > 0 && pipex->cmd_id < (pipex->cmd_num - 1))
		{
			if (i == (pipex->cmd_id * 2) - 2)
				i += 4;
		}
		if (pipex->cmd_id == (pipex->cmd_num - 1) && \
		i == ((pipex->cmd_num - 1) * 2 - 2))
			break ;
		if (i == (pipex->cmd_num - 1) * 2)
			break ;
		if (close (pipex->tubs[i]) == -1)
		{
			ft_free_all(pipex);
			print_error(NULL, NULL, 1);
		}
	}
}

static void	cmd_to_cmd(t_pipex *pipex)
{
	if (close (pipex->tubs[pipex->cmd_id * 2 - 2 + 1]) == -1 || \
	dup2(pipex->tubs[pipex->cmd_id * 2 - 2], STDIN_FILENO) == -1 || \
	close (pipex->tubs[pipex->cmd_id * 2 - 2]) == -1 || \
	close (pipex->tubs[pipex->cmd_id * 2]) == -1 || \
	dup2(pipex->tubs[pipex->cmd_id * 2 + 1], STDOUT_FILENO) == -1 || \
	close (pipex->tubs[pipex->cmd_id * 2 + 1]) == -1)
	{
		ft_free_all(pipex);
		print_error(NULL, NULL, 1);
	}
}

static void	file_to_cmd(t_pipex *pipex)
{
	pipex->file.in = input_check(pipex->file.f_in);
	if (dup2(pipex->file.in, STDIN_FILENO) == -1 || \
	close (pipex->file.in) == -1 || close (pipex->tubs[0]) == -1 || \
	dup2(pipex->tubs[1], STDOUT_FILENO) == -1 || \
	close (pipex->tubs[1]) == -1)
	{
		ft_free_all(pipex);
		print_error(NULL, NULL, 1);
	}	
}

void	manage_pipes(t_pipex *pipex)
{
	close_pipes_for_child(pipex);
	if (pipex->cmd_id > 0 && pipex->cmd_id < (pipex->cmd_num - 1))
		cmd_to_cmd(pipex);
	else if (pipex->cmd_id == 0)
		file_to_cmd(pipex);
	if (pipex->cmd_id == pipex->cmd_num - 1)
	{
		pipex->file.out = output_check(pipex->file.f_out);
		if (close (pipex->tubs[pipex->cmd_id * 2 - 2 + 1]) == -1 || \
		dup2(pipex->tubs[pipex->cmd_id * 2 - 2], STDIN_FILENO) == -1 || \
		close (pipex->tubs[pipex->cmd_id * 2 - 2]) == -1 || \
		dup2(pipex->file.out, STDOUT_FILENO) == -1 || \
		close (pipex->file.out) == -1)
		{
			ft_free_all(pipex);
			print_error(NULL, NULL, 1);
		}
	}
}
