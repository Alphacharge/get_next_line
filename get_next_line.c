/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:03 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/23 15:15:35 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isinset(char const c, char const *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != c && ptr[i] != '\0')
		i++;
	if (ptr[i] == c)
		return (i);
	else
		return (-1);
}

void	*read_and_join(char *line, char **cur_line, const int fd, int *ret)
{
	while (ft_isinset('\n', *cur_line) == -1)
	{
		*ret = read(fd, line, BUFFER_SIZE);
		line[*ret] = '\0';
		if (*ret <= 0)
			break ;
		*cur_line = ft_strjoin(*cur_line, line);
		if (*cur_line == NULL)
			return (NULL);
	}
	return (*cur_line);
}

void	*hack_and_stack(char *line, char **cur_line, char **str_ret, int *pos)
{
	*str_ret = ft_substr(*cur_line, 0, (*pos) + 1);
	if (*str_ret == NULL )
	{
		if (cur_line[0][0] != '\0')
			free(cur_line);
		return (NULL);
	}
	ft_memcpy(line, &((*cur_line)[(*pos) + 1]), ft_strlen(*cur_line) - (*pos));
	return (*str_ret);
}

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*str_ret;
	char		*cur_line;
	int			ret;
	int			pos;

	if (fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE < 1)
		return (NULL);
	line[BUFFER_SIZE] = '\0';
	cur_line = ft_strdup(line);
	if (cur_line == NULL)
		return (NULL);
	read_and_join(line, &cur_line, fd, &ret);
	pos = ft_isinset('\n', cur_line);
	if (pos == -1 && ret == 0)
		pos = ft_isinset('\0', cur_line);
	hack_and_stack(line, &cur_line, &str_ret, &pos);
	free(cur_line);
	if (str_ret[0] == '\0')
	{
		free(str_ret);
		return (NULL);
	}
	return (str_ret);
}

// #include <stdio.h>
// #include <strings.h>
// #include <fcntl.h>
// #define RED "\033[1;31m"
// #define GREEN "\033[01;32m"
// #define NC "\033[0m"

// int main(void)
// {
// 	int	i;
// 	int	fd1;
// 	char *str;
// 	i=5;
// 	fd1 = open("./file.txt", O_RDONLY);
// 	if (fd1 == -1)
// 		printf("open failed");
// 	while(i > 0)
// 	{
// 		str = get_next_line(fd1);
// 		printf(RED"Str = ||"GREEN"%s"RED"||"NC, str);
// 		i--;
// 		free(str);
// 	}
// 	// system("leaks a.out");
// 	return(1);
// }