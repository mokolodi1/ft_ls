#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/01/22 20:46:55 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			ft_ls

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g
LIBFT =			"libft/"

COMPILED =		main.o \
				handle_ls.o \
				handle_directories.o \
				handle_directory.o \
				print_entries.o \
				print_entry.o \
				make_entry.o \
				sort_list_strings.o \
				sort_list_entries.o \
				compare_last_modified_time.o \
				print_total_block_size.o \
				prepare_file_options.o \
				print_file_options.o \
				print_file_permissions.o \
				lstat_if_sym.o \
				free_entry.o \
				get_file_type_char.o \
				should_print_folder.o \
				should_print_entry.o \
				directory_open_failed.o \
				get_readlink_string.o

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIBFT) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
