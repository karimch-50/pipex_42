/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:05:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:46:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (2);
	return (0);
}

int	is_script(char *str)
{
	if (str[0] == '/' || (str[0] == '.' && str[1] == '/') || \
	(str[0] == '.' && str[1] == '.' && str[2] == '/') || \
	ft_strnstr(str, ".sh", ft_strlen(str)))
		return (1);
	return (0);
}

/* count numbers of caracters of the name of a script */
static int	count_for_script(char *str)
{
	int	count;

	count = 0;
	while (str[count] && ft_strncmp(&str[count], ".sh", 3))
		count++;
	count += 3;
	return (count);
}

/* count numbers of caracters inside quotes */
static int	count_letters(char *str, int *start)
{
	int	count;
	int	q;

	count = 0;
	if (is_script(str))
		count = count_for_script(str);
	else if (is_quote(str[count]))
	{
		q = is_quote(str[count]);
		count++;
		(*start) = count;
		while (str[count] && q != is_quote(str[count]))
			count++;
	}
	else
	{
		while (str[count] && str[count] != ' ')
			count++;
	}
	return (count);
}

/* get all the caracters inside quotes in a singel word */
char	*get_one_arg(char *str)
{
	char	*output;
	int		count;
	int		start;
	int		k;

	count = ((k = 0), (start = 0), 0);
	count = count_letters(str, &start);
	output = malloc(count + 1);
	if (!output)
		print_error(NULL, NULL, 1);
	while (start < count)
		output[k++] = str[start++];
	output[k] = '\0';
	return (output);
}
