/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total_block_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 16:14:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/21 17:57:35 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_total_block_size(t_list *entries)
{
	unsigned long long	total;
	char				*string;

	total = 0;
	while (entries)
	{
		total += lstat_if_sym(((t_entry*)entries->data))->st_blocks;
		entries = entries->next;
	}
	ft_putstr("total ");
	string = ft_itoa_ularge(total);
	ft_putstr(string);
	free(string);
	ft_putchar('\n');
}
