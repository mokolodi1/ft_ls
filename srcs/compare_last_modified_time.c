/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_last_modified_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 23:05:56 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/21 18:08:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					compare_last_modified_time(struct stat *first
												, struct stat *second)
{
	return (second->st_mtimespec.tv_sec - first->st_mtimespec.tv_sec);
}
