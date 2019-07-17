/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:52:24 by mrouabeh          #+#    #+#             */
/*   Updated: 2019/07/17 17:01:14 by mrouabeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len++])
		;
	return (len);
}

char				*ft_strdup(char *str)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab_struct;
	int			i;

	i = 0;
	tab_struct = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	while (i < ac)
	{
		tab_struct[i].size = ft_strlen(av[i]);
		tab_struct[i].str = av[i];
		tab_struct[i].copy = ft_strdup(av[i++]);
	}
	tab_struct[i].size = 0;
	tab_struct[i].str = 0;
	tab_struct[i].copy = 0;
	return (tab_struct);
}
