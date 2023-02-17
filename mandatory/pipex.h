/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:19:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/17 16:40:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

# define PATH "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:\
/usr/local/munki"
# define EARGS "Invalid argumments\n"
# define ENSFD ": No such file or directory\n"
# define ECNF ": command not found\n"
# define EPD ": Permission denied\n"

void	pipex(int argc, char **argv, char **env);

/*#######################################################################
#	 							STRUCTS									#
#######################################################################*/

typedef struct s_files
{
	char	*f_in;
	int		in;
	char	*f_out;
	int		out;
}	t_files;

typedef struct s_pipex
{
	pid_t		*pid;
	int			*tubs;
	char		**paths;
	char		**argv;
	char		**env;
	int			cmd_num;
	int			cmd_id;
	char		**cmd_args;
	char		*valid_path;
	t_files		file;
}	t_pipex;

/* open and check infile and outfile */
int		input_check(char *in);
int		output_check(char *out);

/*#######################################################################
#	 						PARSING OF ARGS								#
#######################################################################*/

char	**get_paths(char **env);

int		is_quote(char c);
int		is_script(char *str);
char	*get_one_arg(char *str);
char	**get_command_args(char *cmd);

char	*valid_command_path(char **paths, char *cmd);

/*#######################################################################
#	 							PIPING								    #
#######################################################################*/

void	exec_commands(t_pipex pipex);
void	get_commands(t_pipex *pipex);
void	manage_pipes(t_pipex *pipex);

void	free_double_ptr(char **ptr);
void	ft_free_all(t_pipex *pipex);
void	print_error(char *msg, char *arg, int status);

#endif