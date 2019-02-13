/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:46:53 by seshevch          #+#    #+#             */
/*   Updated: 2019/02/13 14:37:20 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_map(t_vm	*vm, t_players *plr)
{
	int				i;
	unsigned int	j;
	int				k;
	int				bytes;
	char			*str;

	bytes = MEM_SIZE / vm->nbr_plrs;
	i = 0;
	while (plr)
	{
		i = plr->index * bytes;
		j = 0;
		if (vm->map[i] == '0')
			while (j < plr->champ->prog_size / 4)
			{
				k = -1;
				str = ft_itoa_base_x(plr->champ->prog[j], 16);
				while (str[++k])
				{
					vm->map[i] = str[k];
					i++;
				}
				free(str);
				j++;
			}
		plr = plr->next;
	}
}