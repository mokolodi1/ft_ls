/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:00:02 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/24 15:02:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			handle_recursive(t_list **entries, t_options *options)
{
	int				handling_recursives_before;

	options->print_folder_names_before = 1;
	handling_recursives_before = options->handling_recursives;
	options->handling_recursives = 1;
	handle_ls(entries, options);
	options->handling_recursives = handling_recursives_before;
}

static t_bool		link_points_to_itself(t_entry *entry)
{
	char			*link;

	if (entry->is_symlink)
	{
		link = get_readlink_string(entry->long_name);
		if (ft_strequ(link, "./") || ft_strequ(link, "."))
			return (1);
	}
	return (0);
}

static void			find_and_print_recursives(t_list *entries
												, t_options *options)
{
	t_list			*recursives;
	t_entry			*entry;

	recursives = NULL;
	while (entries)
	{
		entry = (t_entry*)entries->data;
		if (entry->stat->st_mode & S_IFDIR
				&& !ft_strequ(entry->short_name, ".")
				&& !ft_strequ(entry->short_name, "..")
				&& !link_points_to_itself(entry))
			ft_list_push_front(&recursives, entry->long_name);
		entries = entries->next;
	}
	if (recursives)
		handle_recursive(&recursives, options);
}

void				handle_directory(char *folder_name, t_list *directory
										, t_bool print_folder
										, t_options *options)
{
	t_list			*entries;
	t_entry			*entry;

	entries = NULL;
	while (directory && (entry = make_entry(folder_name
										, ft_strdup((char*)directory->data)
								, options)))
	{
		ft_list_push_front(&entries, entry);
		directory = directory->next;
	}
	if (entries)
	{
		sort_list_entries(&entries, options);
		if (print_folder)
			print_entries(entries, options);
		if (options->recursive_folders)
			find_and_print_recursives(entries, options);
	}
}
