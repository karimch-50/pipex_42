/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:13 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 16:34:00 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	if (argc != 5)
		print_error(EARGS, NULL, 1);
	pipex.cmd_num = argc - 3;
	pipex.env = envp;
	pipex.argv = argv;
	pipex.file.f_out = argv[argc - 1];
	pipex.file.f_in = argv[1];
	pipex.paths = get_paths(envp);
	pipex.cmd_id = -1;
	pipex.cmd_args = NULL;
	pipex.valid_path = NULL;
	pipex.tubs = malloc(sizeof(int) * (pipex.cmd_num - 1) * 2);
	pipex.pid = malloc(sizeof(int) * pipex.cmd_num);
	if (!pipex.tubs || !pipex.pid)
		print_error(NULL, NULL, 1);
	exec_commands(pipex);
	ft_free_all(&pipex);
}

int	main(int argc, char **argv, char **envp)
{
	pipex(argc, argv, envp);
	return (EXIT_SUCCESS);
}
