/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:09:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:46:45 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_len(char	*str)
{
	int	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

/* join a given path with a given command */
char	*ft_join_command_path(char *path, char *cmd)
{
	char	*output;
	int		i;

	output = malloc(ft_len(cmd) + ft_len(path) + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (path && *path)
		output[i++] = *path++;
	output[i++] = '/';
	while (cmd && *cmd)
		output[i++] = *cmd++;
	output[i] = '\0';
	return (output);
}

/* get the exact command path */
char	*valid_command_path(char **paths, char *cmd)
{
	char	*command_path;

	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	else
	{
		while (*paths)
		{
			command_path = ft_join_command_path(*paths, cmd);
			if (access(command_path, F_OK) == 0)
				return (command_path);
			free(command_path);
			paths++;
		}
	}
	return (NULL);
}

char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	if (*env == NULL)
		*env = PATH;
	return (ft_split(*env + 5, ':'));
}
