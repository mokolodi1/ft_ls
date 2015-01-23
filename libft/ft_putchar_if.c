/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 14:49:19 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/16 14:49:22 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putchar_if(int boolean, char yes, char no)
{
	if (boolean)
		ft_putchar(yes);
	else
		ft_putchar(no);
}
