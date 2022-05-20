/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:15:12 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/20 13:13:44 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include "get_next_line.h"
#define RED "\033[1;31m"
#define GREEN "\033[01;32m"
#define NC "\033[0m"

// void check_leaks();

char	*gnl(int fd);
int main(void)
{
	int	i;
	int	fd1;
	char *str;
	i=5;
	fd1 = open("./file.txt", O_RDONLY);
	if (fd1 == -1)
		printf("open failed");
	while(i > 0)
	{
		str = get_next_line(fd1);
		printf("Str = %s", str);
		i--;
		free(str);
	}
	//  check_leaks();
	// system("leaks a.out");
	return(1);
}