/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:04:54 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/12 11:42:23 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char	*data;
	int		pos;
	int		length;
	int		size;
}	t_list;

char	*get_next_line(int fd);
t_list	*create_list(int i);
void	delete_list(t_list *string);
void	str_append_char(t_list *string, char c);

#endif
