/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:57:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:46:44 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	skip_script(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strncmp(&str[i], ".sh", 3))
		i++;
	i += 3;
	return (i);
}

static int	skip_between_quotes(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = is_quote(str[i]);
	i++;
	if (is_script(&str[i]))
		i += skip_script(&str[i]);
	while (str[i] && q != is_quote(str[i]))
		i++;
	i++;
	return (i);
}

int	count_args(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			count++;
		if (is_quote(str[i]))
			i += skip_between_quotes(&str[i]);
		else
			while (str[i] && str[i] != ' ')
				i++;
	}
	return (count);
}

char	**get_command_args(char *cmd)
{
	char	**output;
	int		i;
	int		j;

	output = malloc(sizeof(char *) * (count_args(cmd) + 1));
	if (!output)
		print_error(NULL, NULL, 1);
	i = ((j = 0), 0);
	while (cmd && cmd[i])
	{
		while (cmd[i] == ' ')
			i++;
		if (cmd[i])
			output[j++] = get_one_arg(&cmd[i]);
		if (is_script(&cmd[i]))
			i += skip_script(&cmd[i]);
		if (is_quote(cmd[i]))
			i += skip_between_quotes(&cmd[i]);
		while (cmd[i] && cmd[i] != ' ')
			i++;
	}
	output[j] = NULL;
	return (output);
}
