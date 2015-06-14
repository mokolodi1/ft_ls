/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:12:25 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/22 23:13:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_time(t_entry *entry)
{
	char			*string;
	time_t			stat_time;
	time_t			difference;

	stat_time = lstat_if_sym(entry)->st_mtimespec.tv_sec;
	string = ft_strdup(ctime(&stat_time));
	write(1, string + 4, 7);
	difference = entry->time_generated - stat_time;
	if (difference > SIX_MONTHS_SECONDS || difference < -SIX_MONTHS_SECONDS)
		write(1, string + 19, 5);
	else
		write(1, string + 11, 5);
	free(string);
}

static void			print_file_size(t_entry *entry, t_strlens *strlens)
{
	if (entry->first_file_size_string)
	{
		ft_putstr_justify_right(entry->first_file_size_string
								, strlens->major + 3, ' ');
		ft_putstr(", ");
		ft_putstr_justify_right(entry->second_file_size_string
								, strlens->file_size - strlens->major - 1, ' ');
	}
	else
	{
		ft_putstr_justify_right(entry->second_file_size_string
								, strlens->file_size + (strlens->major ? 4 : 2)
								, ' ');
	}
}

void				print_file_options(t_entry *entry, t_strlens *strlens)
{
	ft_putchar(entry->file_type_char);
	print_file_permissions(entry);
	ft_putnbr_justify_right(lstat_if_sym(entry)->st_nlink
							, strlens->nlink + 1, ' ');
	ft_putstr(" ");
	ft_putstr_justify_left(entry->username, strlens->username + 2, ' ');
	ft_putstr_justify_left(entry->group_name, strlens->group_name, ' ');
	print_file_size(entry, strlens);
	ft_putstr(" ");
	print_time(entry);
}
