/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:15:04 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/23 18:51:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		destroy_list(t_list *list, void (*free_inside)())
{
	if (list->next != NULL)
		destroy_list(list->next, free_inside);
	if (free_inside)
		free_inside(list->data);
	free(list);
}

void			ft_list_clear(t_list **begin_list, void (*free_inside)())
{
	destroy_list(*begin_list, free_inside);
	*begin_list = NULL;
}
