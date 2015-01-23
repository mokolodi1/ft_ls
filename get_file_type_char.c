/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:59:36 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/22 22:11:41 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				get_file_type_char(t_entry *entry)
{
	if (entry->is_symlink)
		return ('l');
	if (S_ISBLK(entry->stat->st_mode))
		return ('b');
	else if (entry->stat->st_mode & S_IFCHR)
		return ('c');
	else if (S_ISSOCK(entry->stat->st_mode))
		return ('s');
	else if (entry->stat->st_mode & S_IFIFO)
		return ('p');
	else if (entry->stat->st_mode & S_IFDIR)
		return ('d');
	return ('-');
}
