/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:40 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/13 12:35:23 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "get_next_line.h"

char	*gnl(int fd)
{
	static t_list	**list;
	t_list *tmp;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	tmp = ft_lstiter(*list, fd);
	if (tmp == NULL)
	{
		tmp = ft_lstnew(fd);
		if (tmp == NULL)
		{
			ft_lstclear(list);
			return (NULL);
		}
		*list = ft_lstaddfront(list, tmp);
	}
	while (1)
	{
		read(fd, tmp->data, BUFFER_SIZE);
		
	}
}
