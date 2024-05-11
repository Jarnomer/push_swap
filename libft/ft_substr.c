/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:59 by jmertane          #+#    #+#             */
/*   Updated: 2023/11/26 11:10:56 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	ln;

	ln = ft_strlen(s);
	if (!s || !*s || start >= ln)
		return ((ft_strdup("")));
	if (len > ln - start)
		len = ln - start;
	new = ft_calloc(len + 1, sizeof(char));
	if (new)
		ft_strlcpy(new, s + start, len + 1);
	return (new);
}
