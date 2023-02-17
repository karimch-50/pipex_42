/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:12:14 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 12:46:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	input_check(char *in)
{
	int	fd;

	if (access (in, F_OK) == -1)
		print_error(ENSFD, in, 0);
	if (access (in, R_OK))
		print_error(EPD, in, 0);
	fd = open(in, O_RDONLY);
	if (fd == -1)
		print_error(NULL, NULL, 0);
	return (fd);
}

int	output_check(char *out)
{
	int	fd;

	if (access (out, F_OK) == 0 && access (out, W_OK) != 0)
		print_error(EPD, out, 1);
	fd = open(out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		print_error(NULL, NULL, 1);
	return (fd);
}
