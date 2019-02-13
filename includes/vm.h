/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:21:40 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/13 14:21:17 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libftprintf/includes/ft_printf.h"
# include <fcntl.h>
# include "op.h"

typedef struct s_vm			t_vm;
typedef struct s_players	t_players;

/*
** 1
*/

struct						s_players
{
	int						index;
	header_t				*champ;
	t_players				*next;
};

struct						s_vm
{
	int						nbr_cycles;
	int						nbr_plrs;
	unsigned char			map[MEM_SIZE];
	t_players				*champs;
};

/*
** 2
*/

void						error(char *line);
unsigned int				reverse(unsigned int b);

void						parce_champ(header_t *champ, int fd);

void						vm_map(t_vm	*vm, t_players *plr);
#endif
