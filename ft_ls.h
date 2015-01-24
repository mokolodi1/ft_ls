/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 12:55:38 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/24 15:02:42 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** stdlib.h: malloc, free
** stdio.h: perror
** dirent.h: opendir, closedir, readdir, DIR*
** sys/stat.h: stat stuff
** errno.h: error numbers
** pwd.h: get owner of file
** grp.h: get group name of file
** time.h: time, ctime
** sys/types.h: uintmax_t, etc.
** sys/xattr.h: listxattr
*/
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include "libft.h"
# include <sys/stat.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>

# define READLINK_BUFSIZE				256
# define SIX_MONTHS_SECONDS				15778500

typedef char			t_bool;
typedef struct stat		t_stat;

typedef struct			s_options
{
	t_bool		long_format;
	t_bool		recursive_folders;
	t_bool		show_all;
	t_bool		reverse_sort;
	t_bool		sort_time_modified;
	t_bool		print_folder_names_before;
	t_bool		one_per_line;
	t_bool		printed_folder_already;
	t_bool		should_handle_screwups;
	t_bool		handling_screwups;
	t_bool		handling_recursives;
}						t_options;

/*
** stat, lstat, username, group, and date:
** these are only set if the -l is specified. Do not free username,
** group, or date_string because the internet said not to.
*/

/*
** first_file_size_string only holdes major numbers, second holds
** either minor numbers or the file size
*/

typedef struct			s_entry
{
	char		*short_name;
	char		*long_name;
	t_stat		*stat;
	t_stat		*lstat;
	time_t		time_generated;
	char		file_type_char;
	char		*username;
	char		*group_name;
	char		*first_file_size_string;
	char		*second_file_size_string;
	int			is_symlink;
}						t_entry;

/*
** holds the max string length of the entries (for printing out with -l options)
*/

typedef struct			s_strlens
{
	int			nlink;
	uintmax_t	username;
	uintmax_t	group_name;
	int			major;
	int			file_size;
}						t_strlens;

void					handle_ls(t_list **arguments, t_options *options);
void					read_through_directory(char *folder_name
												, t_list **directory_list
												, t_list **screw_ups);
void					handle_directories(t_list *folder_name
													, t_list *directory
													, t_options *options);
void					handle_directory(char *folder_name
													, t_list *directory
													, t_bool print_folder
													, t_options *options);
void					print_entries(t_list *entries, t_options *options);
void					print_entry(t_entry *entry
													, t_options *options
													, t_strlens *strlens);
void					print_total_block_size(t_list *entries);
void					print_file_options(t_entry *entry, t_strlens *strlens);
void					print_file_permissions(t_entry *entry);
void					prepare_file_options(t_strlens *strlens
													, t_list *entries
													, t_options *options);
t_entry					*make_entry(char *folder, char *entry
													, t_options *options);
void					sort_list_strings(t_list **list, t_options *options);
void					sort_list_entries(t_list **list, t_options *options);
int						compare_last_modified_time(t_stat *first
													, t_stat *second);
t_stat					*lstat_if_sym(t_entry *entry);
char					get_file_type_char(t_entry *entry);
void					free_entry(t_entry *entry);
int						should_print_folder(char *long_name
													, t_options *options);
t_bool					should_print_entry(t_entry *entry, t_options *options);
void					directory_open_failed(char *failing_name
													, t_list **screw_ups);
char					*get_readlink_string(char *link_path);

#endif
