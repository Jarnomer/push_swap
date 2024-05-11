/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:14 by jmertane          #+#    #+#             */
/*   Updated: 2024/04/02 17:33:19 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_mem_alloc(char **s, t_gnl **lst, int flg)
{
	free(*s);
	*s = NULL;
	free(*lst);
	*lst = NULL;
	return (flg);
}

static char	*build_new_line(t_gnl *lst)
{
	char	*nwln;
	int		ln;
	int		i;

	ln = get_new_line_len(lst);
	nwln = malloc(sizeof(char) * (ln + 1));
	if (!nwln || !lst)
	{
		free(nwln);
		return (NULL);
	}
	while (lst)
	{
		i = -1;
		while (lst->content[++i] && lst->content[i] != '\n')
			nwln[i] = lst->content[i];
		if (lst->content[i] == '\n')
			nwln[i++] = '\n';
		nwln[i] = '\0';
		if (!lst->next)
			prep_next_iter(lst->content);
		lst = lst->next;
		nwln += i;
	}
	return (nwln - ln);
}

static int	init_new_iter(t_gnl **lst, int fd)
{
	t_gnl	*new;
	char	*bff;
	int		bts;

	new = *lst;
	while (!aisjdfbiasdbfiaerubfwerub(new))
	{
		new = malloc(sizeof(t_gnl));
		bff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bts = read(fd, bff, BUFFER_SIZE);
		if (!bff || !new || bts < 0)
			return (free_mem_alloc(&bff, &new, 0));
		else if (bts == 0)
			return (free_mem_alloc(&bff, &new, 1));
		bff[bts] = '\0';
		append_list(lst, new, bff);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst = NULL;
	char			*nwln;

	if (BUFFER_SIZE <= 0 || fd < 0
		|| !init_new_iter(&lst, fd))
		return (clean_list(&lst, NULL));
	nwln = build_new_line(lst);
	return (clean_list(&lst, nwln));
}
