/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:03 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/20 13:30:23 by rbetz            ###   ########.fr       */
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

void	*read_and_join(char **cur_line, const int fd, int *ret, char *line)
{
	while (ft_isinset('\n', *cur_line) == 0)
	{
		*ret = read(fd, line, BUFFER_SIZE);
		line[*ret] = '\0';
		// //printf("%d\n", ret);
		if (*ret <= 0)
			break ;
		*cur_line = ft_strjoin(*cur_line, line);
		if (*cur_line == NULL)
			return (NULL);
	}
	return(*cur_line);
}

void	*hack_and_stack(int *pos, char **cur_line, char **str_ret, int *ret, char *line)
{
	// //printf("++\n||%s||\n||%s||\n",*cur_line, line);
	if (*pos == 0 && ft_strlen(*cur_line) > 0)
		*pos = ft_strlen(*cur_line);
	*str_ret = ft_substr(*cur_line, 0, (*pos) + 1);
	////printf("Address of str_ret: ||%p||\n", str_ret);
	////printf("Address of cur_line: ||%p||\n", cur_line);
	if (*str_ret == NULL || *ret == -1)
	{
		if (cur_line[0][0] != '\0')
			free(cur_line);
		// free(*str_ret);
		return (NULL);
	}
	// //printf("\nLine before copy:%s\n", line);
	ft_memcpy(line, &((*cur_line)[(*pos) + 1]), ft_strlen(*cur_line)-(*pos));
	return(*str_ret);
}

char	*get_next_line(int fd)
{
	static char line[BUFFER_SIZE + 1];
	char		*str_ret;
	char		*cur_line;
	int			ret;
	int			pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line[BUFFER_SIZE] = '\0';
	cur_line = ft_strdup(line);
	if (cur_line == NULL)
		return (NULL);
	read_and_join(&cur_line, fd, &ret, line);
	pos = ft_isinset('\n', cur_line);
	// if (pos == -1)
	// {
	// 	free(cur_line);
	// 	return (NULL);
	// }
	hack_and_stack(&pos, &cur_line, &str_ret, &ret, line);
	//printf("Line after copy:%s,%s,%d,%d\n", line, &cur_line[pos +1], pos + 1, ft_strlen(cur_line)-pos);
	free(cur_line);
	if (str_ret[0] == '\0')
	{
		free(str_ret);
		return (NULL);
	}
	return (str_ret);
}
