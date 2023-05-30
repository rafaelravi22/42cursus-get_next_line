/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafamart <rafamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:57:52 by rafamart          #+#    #+#             */
/*   Updated: 2023/05/30 17:19:45 by rafamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] && str[count] != '\n')
		count++;
	return (count + (str[count] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_check_n(char *buffer)
{
	int	i;
	int	j;
	int	scan;

	scan = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (scan)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			scan = 1;
		buffer[i] = '\0';
		i++;
	}
	return (scan);
}
