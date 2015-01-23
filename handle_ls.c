/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 13:02:14 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/23 18:59:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** reads through the directories and creates a t_list of DIR*
** screw_ups: inputs from the user that are files (not folders) that
** exist (only a thing on the first time running through)
*/

static void			print_screw_ups(t_list *screw_ups, t_list **arguments
									, t_options *options)
{
	t_list			*entries;

	entries = NULL;
	while (screw_ups)
	{
		ft_list_push_front(&entries
							, make_entry("./", (char*)screw_ups->data
											, options));
		ft_list_remove_if(arguments, screw_ups->data, &ft_ptrequ);
		screw_ups = screw_ups->next;
	}
	options->handling_screwups = 1;
	sort_list_entries(&entries, options);
	print_entries(entries, options);
	options->handling_screwups = 0;
}

static void			do_screw_ups_and_handling(t_list **arguments
												, t_list **directory_list
												, t_list **screw_ups
												, t_options *options)
{
	if (*screw_ups && options->should_handle_screwups)
	{
		print_screw_ups(*screw_ups, arguments, options);
		ft_list_clear(screw_ups, NULL);
		options->print_folder_names_before = 1;
	}
	options->should_handle_screwups = 0;
	if (directory_list)
		handle_directories(*arguments, *directory_list, options);
}

static t_bool		should_treat_link_as_screw_up(char *name
													, t_list **arguments
													, t_list *this_argument
													, t_options *options)
{
	t_stat			statistics;
	DIR				*opened;

	if (*(ft_strchr(name, '\0') - 1) == '/')
		return (0);
	if (lstat(name, &statistics))
		ft_list_remove_node(arguments, this_argument, NULL);
	else if (S_ISLNK(statistics.st_mode))
	{
		opened = opendir(name);
		if (opened)
		{
			closedir(opened);
			return (options->long_format);
		}
		return (1);
	}
	return (0);
	(void)arguments;
	(void)this_argument;
}

static void			setup(t_list **directory_list, t_list **screw_ups
							, t_list **arguments, t_list **this_arg)
{
	*directory_list = NULL;
	*screw_ups = NULL;
	*this_arg = *arguments;
}

void				handle_ls(t_list **arguments, t_options *options)
{
	t_list		*directory_list;
	t_list		*this_arg;
	DIR			*opened;
	t_list		*screw_ups;
	char		*folder_name;

	sort_list_strings(arguments, options);
	setup(&directory_list, &screw_ups, arguments, &this_arg);
	while (this_arg)
	{
		folder_name = (char*)this_arg->data;
		if (options->should_handle_screwups
			&& should_treat_link_as_screw_up(folder_name, arguments
												, this_arg, options))
			ft_list_push_back(&screw_ups, folder_name);
		else
		{
			opened = opendir(folder_name);
			ft_list_push_back(&directory_list, opened);
			if (!opened)
				directory_open_failed(folder_name, &screw_ups);
		}
		this_arg = this_arg->next;
	}
	do_screw_ups_and_handling(arguments, &directory_list, &screw_ups, options);
}
