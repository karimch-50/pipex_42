# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:19:15 by kchaouki          #+#    #+#              #
#    Updated: 2023/02/17 16:38:10 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_B = pipex_bonus

LIBFT = libft/libft.a

SRCS = mandatory/pipex.c \
	   mandatory/utiles/io_checks.c \
	   mandatory/utiles/get_one_arg.c \
	   mandatory/utiles/extract_args.c \
	   mandatory/utiles/extract_path.c \
	   mandatory/utiles/get_commands.c \
	   mandatory/utiles/manage_pipes.c \
	   mandatory/utiles/exec_commands.c \
	   mandatory/utiles/ft_free.c \
	   mandatory/utiles/print_error.c
	   
SRCS_B = bonus/pipex_bonus.c \
	   	 bonus/utiles/io_checks.c \
	   	 bonus/utiles/get_one_arg.c \
	   	 bonus/utiles/extract_args.c \
	   	 bonus/utiles/extract_path.c \
	   	 bonus/utiles/get_commands.c \
	   	 bonus/utiles/manage_pipes.c \
	   	 bonus/utiles/exec_commands.c \
	   	 bonus/utiles/get_next_line.c \
	   	 bonus/utiles/get_next_line_utils.c \
	   	 bonus/utiles/here_doc.c \
	   	 bonus/utiles/ft_free.c \
	   	 bonus/utiles/print_error.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror 

CCe = cc $(FLAGS)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft && make clean -C libft 

%.o : %.c
	$(CCe) -c $< -o $@

$(NAME): $(OBJS) mandatory/pipex.h
	$(CCe) $(OBJS) $(LIBFT) -I mandatory/pipex.h -o $(NAME) 

$(NAME_B): $(OBJS_B) bonus/pipex_bonus.h
	$(CCe) $(OBJS_B) $(LIBFT) -o $(NAME_B)

bonus: $(LIBFT) $(NAME_B)

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B) $(LIBFT)

re : fclean all

.PHONY: all clean fclean re bonus