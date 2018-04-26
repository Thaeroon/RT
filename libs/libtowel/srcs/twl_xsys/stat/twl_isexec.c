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

#include <sys/stat.h>
#include <stdbool.h>

bool		twl_isexec(char *path)
{
	struct stat st;

	if (lstat(path, &st) == -1)
		return (false);
	if (st.st_mode & S_IXGRP || st.st_mode & S_IXOTH || st.st_mode & S_IXUSR)
		return (true);
	return (false);
}
