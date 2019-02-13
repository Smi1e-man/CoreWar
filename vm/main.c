/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:34:35 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/13 19:54:22 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			error(char *line)
{
	ft_printf("%s\n", line);
	exit(1);
}

unsigned int	reverse(unsigned int b)
{
	b = (b >> 16 | b << 16);
	b = ((b & 0xFF00FF00) >> 8 | (b & 0x00FF00FF) << 8);
	return (b);
}

// void			vm_carriage(t_vm *vm)
// {
// 	vm->carriage = (t_carriage *)malloc(sizeof(t_carriage));
// 	vm->carriage = 
// }

int		main(int ac, char **av)
{
	header_t	*champ;
	t_players	*plr;
	t_vm		*vm;
	int			fd;
	int			i;

	fd = ac;
	champ = (header_t *)malloc(sizeof(header_t));
	plr = (t_players *)malloc(sizeof(t_players));
	vm = (t_vm *)malloc(sizeof(t_vm));
	fd = open(av[1], O_RDWR);
	//parcing
	parce_champ(champ, fd);
	// 3 players in list
	vm->nbr_plrs = 4;
	plr->champ = champ;
	plr->index = 1;
	plr->next = (t_players *)malloc(sizeof(t_players));
	plr->next->champ = champ;
	plr->next->index = 2;
	plr->next->next = (t_players *)malloc(sizeof(t_players));
	plr->next->next->champ = champ;
	plr->next->next->index = 3;
	plr->next->next->next = (t_players *)malloc(sizeof(t_players));
	plr->next->next->next->champ = champ;
	plr->next->next->next->index = 4;
	plr->next->next->next->next = NULL;
	// map
	ft_memset(vm->map, '0', MEM_SIZE * 2);
	vm_map(vm, plr);
	//carriage
	// vm_carriage();
	//print
	ft_printf("MAP :\n");
	i = -1;
	while (++i < MEM_SIZE * 2)
	{
		if (i == 0 || i == 1)
			ft_printf(RED"%c"EOC, vm->map[i]);
		else if (i == (MEM_SIZE * 2) / vm->nbr_plrs || i == (MEM_SIZE * 2) / vm->nbr_plrs + 1)
			ft_printf(YEL"%c"EOC, vm->map[i]);
		else if (i == ((MEM_SIZE * 2) / vm->nbr_plrs) * 2 || i == ((MEM_SIZE * 2) / vm->nbr_plrs) * 2 + 1)
			ft_printf(BLU"%c"EOC, vm->map[i]);
		else if (i == ((MEM_SIZE * 2) / vm->nbr_plrs) * 3 || i == ((MEM_SIZE * 2) / vm->nbr_plrs) * 3 + 1)
			ft_printf(GRE"%c"EOC, vm->map[i]);
		else
			ft_printf("%c", vm->map[i]);
	}
	ft_printf("\nsize = %d\n", i);
	//print
	return (0);
}