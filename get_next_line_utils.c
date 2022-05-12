/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:07 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/12 11:42:32 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_list(int i)
{
	t_list	*string;
	if (i == 1)
	{
		string = malloc(sizeof(t_list));
		string->data = malloc(128);
		if (string->data == NULL || string == NULL)
			delete_list(string);
		string->pos = 0;
		string->length = 128;
		string->size = i;
		return (string);
	}
	else
	{
		t_list	*more;
		more = malloc(sizeof(t_list));
		more->data = malloc(128 * i);
		if (more->data == NULL || more == NULL)
			delete_list(more);
		more->data = string->data;
		more->pos = string->pos;
		more->length = 128 * i;
		more->size = i;
		delete_list(string);
		return (more);
	}
}

void	delete_list(t_list *string)
{
	free(string->data);
	free(string);
}

void	str_append_char(t_list *string, char c)
{
	if (string->pos >= string->length)
		string = create_list(string->size + 1);
	if (c != '\n' && c != '\0')
	{
		string->pos = string->pos + 1;
		string->data[string->pos] = c;
	}
}

