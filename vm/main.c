/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:34:35 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/13 14:38:21 by seshevch         ###   ########.fr       */
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
	parce_champ(champ, fd);
	vm->nbr_plrs = 3;
	// 3 players in list
	plr->champ = champ;
	plr->index = 0;
	plr->next = (t_players *)malloc(sizeof(t_players));
	plr->next->champ = champ;
	plr->next->index = 1;
	plr->next->next = (t_players *)malloc(sizeof(t_players));
	plr->next->next->champ = champ;
	plr->next->next->index = 2;
	plr->next->next->next = NULL;
	//
	ft_memset(vm->map, '0', MEM_SIZE);
	vm_map(vm, plr);
	//print
	ft_printf("MAP :\n");
	i = -1;
	while (++i < MEM_SIZE)
		ft_printf("%c", vm->map[i]);
	//print
	return (0);
}