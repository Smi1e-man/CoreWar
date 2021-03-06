/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:09:17 by rkulahin          #+#    #+#             */
/*   Updated: 2019/03/25 20:00:28 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			win_player(t_vm *vm, t_players *last)
{
	int key;

	key = 0;
	if (vm->curses == 1)
	{
		mvprintw(45, 128 + 128 / 2 + 10, "Contestant %i, \"%s\", has won !",
		last->index, last->champ->prog_name);
		mvprintw(50, 128 + 128 / 2 + 10, "[EXIT] ------> SHIFT + TAB");
		while (true)
		{
			key = getch();
			if (key == KEY_BTAB)
			{
				endwin();
				exit(1);
			}
		}
	}
	ft_printf("Contestant %i, \"%s\", has won !\n",
	last->index, last->champ->prog_name);
	exit(1);
}

void			print_dump(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < MEM_SIZE * 2)
	{
		if (i % 128 == 0)
		{
			if (i != 0)
				ft_printf("\n");
			ft_printf("%#.4x : ", i / 2);
		}
		ft_printf("%c%c ", vm->map[i], vm->map[i + 1]);
		i += 2;
	}
	ft_printf("\n");
	exit(1);
}

void			replace_map(t_vm *vm, int position, char *ptr, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (position < 0)
		position = position + 8192;
	while (i < nb)
	{
		vm->map[(position + j) % 8192] = ptr[j];
		i++;
		j++;
	}
}

void			privetstvie(t_vm *vm)
{
	t_players	*tmp;
	int			i;

	if (vm->curses == 1)
		return ;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (++i != 5)
	{
		tmp = vm->players;
		while (tmp)
		{
			if (tmp->index == i)
			{
				ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
				i, tmp->champ->prog_size, tmp->champ->prog_name,
				tmp->champ->comment);
				break ;
			}
			tmp = tmp->next;
		}
	}
}
