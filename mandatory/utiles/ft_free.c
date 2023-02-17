/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:03:51 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:46:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		i++;
	while (i)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

void	ft_free_all(t_pipex *pipex)
{
	free_double_ptr(pipex->paths);
	free(pipex->tubs);
	free(pipex->pid);
	free_double_ptr(pipex->cmd_args);
	free(pipex->valid_path);
}
