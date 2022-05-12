/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:40 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/12 15:38:16 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size < 1 || count < 1)
	{
		size = 0;
		count = 1;
	}
	if (size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (count > 1 || size > 1)
	{
		ptr[count * size] = '\0';
		if (size > 1)
			size--;
		if (count > 1)
			count--;
	}
	
	return (ptr);
}

char	*gnl(int fd)
{
	char c;
	int	n;
	int	i;
	static char	*str;

	n = 1;
	str = ft_calloc(BUFFER_SIZE, n);
	while (c != '\n' && c != '\0')
	{
		read(fd,&c,1);
		if (i == BUFFER_SIZE)
			{
				n++;
				str = realloc(BUFFERSIZE, n);
			}
		i++;
	}
}
