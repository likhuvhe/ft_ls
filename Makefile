# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhuvhe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 13:14:56 by lkhuvhe           #+#    #+#              #
#    Updated: 2019/09/17 18:21:05 by lkhuvhe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAG = -Wall -Werror -Wextra
CC = gcc
OPTION = -o
SRC = check_options.c compare.c del.c display_list.c ft_list_parsed_dir.c ft_ls.c ft_lst_rev.c \
	  ft_sort_time.c ft_sort.c ft_timecmp.c is_option.c long_ls.c print_ls.c print_parsed_f_d.c \
	  get_exattr.c full_path.c recurse.c creat_lst_dir.c ft_get_link_path.c sort_lst_ascci.c\
	  just_ls.c the_lst.c
LIB = -L libft/ -lft -I
all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) $(OPTION) $(NAME) $(SRC) $(LIB) $(FLAG)

clean:
	@make fclean -C libft/

fclean: clean
	@rm -f $(NAME)

re: fclean all
