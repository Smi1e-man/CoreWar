/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:21:40 by rkulahin          #+#    #+#             */
/*   Updated: 2019/02/13 19:44:34 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libftprintf/includes/ft_printf.h"
# include <fcntl.h>
# include "op.h"

/*
** color types
*/
# define EOC "\033[0m"

# define RED "\033[1;31m"
# define GRE "\033[32m"
# define BLU "\033[34m"
# define YEL "\033[1;33m"
# define VIO "\033[35m"
# define BLA "\033[30m"
# define WHI "\033[1;37m"
/*
** structers
*/
typedef struct s_vm			t_vm;
typedef struct s_players	t_players;
typedef struct s_carriage	t_carriage;

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
	unsigned char			map[MEM_SIZE * 2];

	t_players				*champs;
	t_carriage				*carriage;
};

struct						s_carriage
{
	int						position;
	int						carry;
	int						nbr_plr;

	unsigned int			regist[REG_NUMBER];

	int						live;
	char					operation[2];
	int						cycle;

	struct s_carriage		*next;
};

/*
** 2
*/

void						error(char *line);
unsigned int				reverse(unsigned int b);

void						parce_champ(header_t *champ, int fd);

void						vm_map(t_vm	*vm, t_players *plr);
#endif
