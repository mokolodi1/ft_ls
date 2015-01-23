/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 20:58:23 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/28 21:35:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		write_chars(char *first, char *now, long long number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

char			*ft_itoa_large(intmax_t number)
{
	char	*new;
	int		length;

	if (number == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_digits(number);
	new = malloc(sizeof(char) * (length + (number < 0) + 1));
	if (number < 0)
	{
		new[0] = '-';
		write_chars(new + 1, new + length, 0 - number);
		new[length + 1] = '\0';
	}
	else
	{
		write_chars(new, new + length - 1, number);
		new[length] = '\0';
	}
	return (new);
}
