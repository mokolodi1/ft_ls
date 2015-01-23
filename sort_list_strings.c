/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 21:45:23 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/16 17:57:50 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_strcmp_reverse(char *first, char *second)
{
	return (-ft_strcmp(first, second));
}

void				sort_list_strings(t_list **list, t_options *options)
{
	if (options->reverse_sort)
		ft_list_sort(list, (int (*)(void*, void*))&ft_strcmp_reverse);
	else
		ft_list_sort(list, (int (*)(void*, void*))&ft_strcmp);
}
