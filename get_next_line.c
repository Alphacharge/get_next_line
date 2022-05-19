/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:03 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/19 14:38:50 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//Returns the Array index of the searched char
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
	while (ft_isinset('\n', cur_line) == 0)
	{
		ret = read(fd, line, BUFFER_SIZE);
		// printf("%d\n", ret);
		if (ret <= 0)
			break ;
		cur_line = ft_strjoin(cur_line, line);
		if (cur_line == NULL)
			return (NULL);
	}
	pos = ft_isinset('\n', cur_line);
	if (pos == 0 && ft_strlen(cur_line) > 0)
		pos = ft_strlen(cur_line);
	str_ret = ft_substr(cur_line, 0, pos +1);
	//printf("Address of str_ret: ||%p||\n", str_ret);
	//printf("Address of cur_line: ||%p||\n", cur_line);
	if (str_ret == NULL || ret == -1)
	{
		//printf("hi");
		free(cur_line);
		free(str_ret);
		return (NULL);
	}
	// printf("\nLine before copy:%s\n", line);
	ft_memcpy(line, &cur_line[pos +1], ft_strlen(cur_line)-pos);
	// printf("Line after copy:%s,%s,%d,%d\n", line, &cur_line[pos +1], pos + 1, ft_strlen(cur_line)-pos);
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
// #include "get_next_line.h"
// #include "get_next_line_utils.c"


// #define RED "\033[1;31m"
// #define GREEN "\033[01;32m"
// #define NC "\033[0m"

// char	*gnl(int fd);
// int main(void)
// {
// 	int	i;
// 	int	fd1;
// 	i=5;
// 	fd1 = open("./file.txt", O_RDONLY);
// 	if (fd1 == -1)
// 		//printf("open failed");
// 	while(i > 0)
// 	{
// 		//printf("%s", get_next_line(fd1));
// 		i--;
// 	}
// 	return(1);
// }

