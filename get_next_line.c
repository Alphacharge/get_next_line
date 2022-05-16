/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:03 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/16 16:17:32 by rbetz            ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	size = (size_t)ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, &s[start], len);
	ptr[len] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char line[BUFFER_SIZE + 1];
	char		*str_ret;
	char		*cur_line;
	int			ret;
	int			pos;

	cur_line = ft_strdup(line);
	while (ft_isinset('\n', cur_line) == 0)
	{
		ret = read(fd, line, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		cur_line = ft_strjoin(cur_line, line);
	}
	pos = ft_isinset('\n', cur_line);
	if (pos == 0 && ft_strlen(cur_line) > 0)
		pos = ft_strlen(cur_line);
	str_ret = ft_substr(cur_line, 0, pos +1);
	ft_memcpy(line, &cur_line[pos +1], ft_strlen(cur_line)-pos);
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
// 		printf("open failed");
// 	while(i > 0)
// 	{
// 		printf("%s", get_next_line(fd1));
// 		i--;
// 	}
// 	return(1);
// }


	// cur_line = ft_strdup("");
	// // if (ft_strlen(line)!= 0)
	// // 	ft_memcpy(cur_line, line, ft_strlen(line));
	// while (ft_isinset('\n', cur_line) == 0)
	// {
	// 	// printf("->%s\n", line);
	// 	ret = read(fd, line, BUFFER_SIZE);
	// 	line[BUFFER_SIZE] = '\0';
	// 	//  printf("-->%s\n", line);
	// 	if (ret <= 0)
	// 		break ;
	// 	// printf("-->>%s\n", cur_line);
	// 	cur_line = ft_strjoin(cur_line, line);
	// 	// printf("-->>>%s\n", cur_line);
	// }
	// if (ret > 0)
	// {
	// 	str_ret = malloc(sizeof(char) * (ft_isinset('\n', cur_line) + 2));
	// 	str_ret[ft_isinset('\n', cur_line)+1] = '\0';
	// 	ft_memcpy(str_ret, cur_line, ft_isinset('\n', cur_line));
	// 	// ft_memcpy(line, &cur_line[ft_isinset('\n', cur_line)+1], (BUFFER_SIZE - ft_isinset('\n', cur_line)));
	// 	// line[BUFFER_SIZE - ft_isinset('\n', cur_line) + 1] = '\0';
	// 	// printf("-->%s\n", line);
	// }
	// else
	// 	str_ret = malloc(sizeof(char) * ft_isinset('\0', cur_line));