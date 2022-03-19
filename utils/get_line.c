/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:45:41 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/15 10:56:09 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

void	ft_strcpy(char	*dst, char	*src, char c)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		free(src);
	}
	dst[i++] = c;
	dst[i] = 0;
}

char	*ft_strjoin(char c, char *str)
{
	char	*line;

	line = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!line)
	{
		free(str);
		write(2, "ERROR!\n", 7);
		return (0);
	}
	ft_strcpy(line, str, c);
	return (line);
}

char	*get_line(void)
{
	char	c;
	char	*line;

	c = 0;
	line = NULL;
	while (c != '\n' && read(0, &c, 1) > 0)
		line = ft_strjoin(c, line);
	return (line);
}
