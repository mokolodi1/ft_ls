/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat_if_sym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:38:10 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/16 15:38:12 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat				*lstat_if_sym(t_entry *entry)
{
	if (entry->is_symlink)
		return (entry->lstat);
	else
		return (entry->stat);
}
