/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:15:12 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/12 10:56:48 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <fcntl.h>

#define RED "\033[1;31m"
#define GREEN "\033[01;32m"
#define NC "\033[0m"

int main(void)
{
	int	i;
	int	fd1;
	i=5;
	fd1 = open("file.txt", O_RDONLY);
	while(i > 0)
	{
		printf("%s", get_next_line(fd1));
		i--;
	}
	return(1);
}