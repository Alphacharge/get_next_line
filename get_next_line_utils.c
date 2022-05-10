/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:07 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/10 11:37:21 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	create_list(int i)
{
	if (i == 1)
	{
		t_list	string;
		string = malloc(sizeof(t_list));
		string->data = malloc(128);
		if (string->data == NULL || string == NULL)
			delete_list(string);
		string->pos = 0;
		string->length = 128;
		string->size = i;
	}
	else
	{
		t_list	more;
		more = malloc(sizeof(t_list));
		more->data = malloc(128 * i);
		if (more->data == NULL || more == NULL)
			delete_list(more);
		more->data = string->data;
		more->pos = string->pos;
		more->length = 128 * i;
		more->size = i;
		string = more;
		delete_list(more);
	}
	return (string);
}

void	delete_list(t_list string)
{
	free(string->data);
	free(string);
}

void	str_append_char(t_list string, char c)
{
	if (string->pos >= string->length)
		string = create_list(string->size + 1);
	if (c != '\n' && c != '\0')
	{
		string->pos = string->pos + 1;
		string-data[string->pos] = c;
	}
	else
	{
		string = print_string(string);
	}
}

t_list	print_string(t_list string)
{
	int i;
	while (string->pos > i)
	{
		write(1, string->data[i], 1);
		i++;
	}
	write(1, '\n', 1);
	
}
