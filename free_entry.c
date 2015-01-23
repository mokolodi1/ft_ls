/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:37:33 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/23 19:40:18 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				free_entry(t_entry *entry)
{
	if (entry->short_name)
		free(entry->short_name);
	if (entry->long_name)
		free(entry->long_name);
	if (entry->stat)
		free(entry->stat);
	if (entry->lstat)
		free(entry->lstat);
	if (entry->username)
		free(entry->username);
	if (entry->group_name)
		free(entry->group_name);
	if (entry->first_file_size_string)
		free(entry->first_file_size_string);
	if (entry->second_file_size_string)
		free(entry->second_file_size_string);
	if (entry)
		free(entry);
}
