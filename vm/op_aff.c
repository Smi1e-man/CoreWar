/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:39:34 by rkulahin          #+#    #+#             */
/*   Updated: 2019/03/04 10:39:23 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char		*space_byte_print(char *ptr)
{
	char	*str;

	str = ptr;
	return (str);
}

void		op_aff(t_vm *vm, t_carriage *cr)
{
	char	*str_cotage;
	int		*args;
	int		l;

	l = 0;
	str_cotage = valid_str(vm, cr->position, 2);
	args = check_arg(vm_atoi_16(str_cotage));
	if (args[0] == T_REG)
	{
		ft_printf("%c", (unsigned char)vm_atoi_16(valid_str(vm, cr->position +
		2, 2)));
		l = 16;
	}
	if ((vm->nbr_log & l) == 16)
		ft_printf("ADV %i (%#x -> %#x) %s \n",
		3, cr->position / 2, (cr->position + 6) / 2,
		space_byte_print(valid_str(vm, cr->position - 2, 6)));
	if (args[0] == T_REG)
		cr->position = cr->position + 6;
	else if (args[0] == T_IND)
		cr->position = cr->position + 8;
	else if (args[0] == T_DIR)
		cr->position = cr->position + 12;
	else
		cr->position += 4;
}