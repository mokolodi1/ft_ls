/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_print_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:55:03 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/22 23:14:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** The 42 norm does not allow for multiple lines in return
** statements.
*/

t_bool				should_print_entry(t_entry *entry, t_options *options)
{
	t_bool			bleh;

	bleh = *entry->short_name != '.'
		|| options->show_all
		|| options->handling_screwups;
	return (bleh);
}
