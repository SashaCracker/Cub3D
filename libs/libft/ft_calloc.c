/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:11:38 by sgummy            #+#    #+#             */
/*   Updated: 2022/04/24 23:11:38 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (void *) malloc(count * size);
	if (!res)
		return (NULL);
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
