/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:15:12 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/16 17:51:34 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include "get_next_line.h"
#define RED "\033[1;31m"
#define GREEN "\033[01;32m"
#define NC "\033[0m"

void check_leaks();

char	*gnl(int fd);
int main(void)
{
	int	i;
	int	fd1;
	char *str;
	i=2;
	fd1 = open("./file.txt", O_RDONLY);
	if (fd1 == -1)
		printf("open failed");
	while(i > 0)
	{
		str = get_next_line(fd1);
		printf("%s", str);
		i--;
		free(str);
	}
	check_leaks();
	return(1);
}