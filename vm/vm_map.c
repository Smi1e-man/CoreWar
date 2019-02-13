/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:46:53 by seshevch          #+#    #+#             */
/*   Updated: 2019/02/13 19:45:49 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*vm_itoa_16(long long numb)
{
	char		*str;
	int			i;
	long long	v1;

	i = 8;
	str = ft_memset(ft_strnew(i), '0', 8);
	while (i-- != 0)
	{
		if (ABS(numb % 16) > 9)
			v1 = ABS(numb % 16) - 10 + 'a';
		else
			v1 = ABS(numb % 16) + '0';
		str[i] = v1;
		numb /= 16;
	}
	return (str);
}

void	vm_map(t_vm	*vm, t_players *plr)
{
	int				i;
	unsigned int	j;
	int				k;
	int				bytes;
	char			*str;

	bytes = MEM_SIZE * 2 / vm->nbr_plrs;
	i = 0;
	while (plr)
	{
		i = (plr->index - 1) * bytes;
		j = 0;
		while (j < plr->champ->prog_size / 4)
		{
			k = -1;
			str = vm_itoa_16(plr->champ->prog[j]);
			while (str[++k])
			{
				// if (i >= 4096)
				// 	vm->map[i % 4096] = str[k];
				// else
					vm->map[i] = str[k];
				i++;
			}
			free(str);
			j++;
		}
		//carriage
		plr = plr->next;
	}
}