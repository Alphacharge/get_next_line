/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:03 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/13 17:29:12 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	ft_isinset(char const c, char const *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != c && ptr[i] != '\0')
		i++;
	if (ptr[i] != '\0')
		return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	static char line[1024];
	char		*str_ret;
	char		*cur_line;
	int			ret;

	cur_line = "";
	str_ret = "";
	while (ft_isinset('\n', cur_line) == 0)
	{
		// printf("haha\n");
		ret = read(fd, line, BUFFER_SIZE);
		printf("%s\n", line);
		if (ret < 0)
			break ;
		cur_line = ft_strjoin(cur_line, line);
	}
	if (ret > 0)
		ft_memcpy(str_ret, cur_line, ft_isinset('\n', cur_line));
	else
		ft_memcpy(str_ret, cur_line, ft_isinset('\0', cur_line));
	return (str_ret);
}
