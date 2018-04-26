/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "twl_stdlib.h"
#include "twl_ctype.h"
#include "twl_xstring.h"

bool				twl_str_is_int(char *s)
{
	char			*tmp;
	int				is_int;

	if (twl_strlen(s) == 0)
		return (false);
	tmp = twl_itoa(twl_atoi(s));
	is_int = twl_strequ(tmp, s);
	free(tmp);
	return (is_int);
}
