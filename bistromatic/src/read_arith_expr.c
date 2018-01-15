/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arith_expr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:38:09 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/15 15:34:24 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"

/*
** check if charset contains character c
*/

static int	in_charset(char c, const char *charset)
{
	return ((bsm_strchr(charset, c) ? 1 : 0));
}

/*
** check if arithmetic expression contains unknown operators or
** characters that are not contained in charset
*/

static int	has_repeat_characters(const char *charset)
{
	int	len;
	int	i;

	len = 0;
	while (charset[len])
	{
		i = 0;
		while (charset[i])
		{
			if (i != len && charset[i] == charset[len])
				return (1);
			i++;
		}
		len++;
	}
	return (0);
}

/*
** check if arithmetric expression is valid:
**	contains only operators and digits from the provided charset
*/

static int	arith_expr_invalid(const char *arith_expr, const char *charset,
				int expr_len)
{
	int	i;
	int	len;

	(void)expr_len;
	if (!charset || !arith_expr)
		return (1);
	i = 0;
	len = bsm_strlen(arith_expr);
	while (i < len)
	{
		if (!(bsm_is_operator(arith_expr[i])) &&
			!(in_charset(arith_expr[i], charset)))
		{
			bsm_putstr("syntax error", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** store base charset and input length from av[1] and av[2]
** validate charset:
**	contains no duplicate symbols
**	has at least two members
**	contains no operators
*/

int			bsm_parse_commandline_args(int ac, char **av, int *stdin_len,
				char **charset)
{
	int		size_charset;

	if (ac != 3)
		return (0);
	*stdin_len = bsm_atoi(av[2]);
	if (*stdin_len <= 0)
	{
		bsm_putstr("syntax error", 2);
		return (0);
	}
	size_charset = bsm_strlen(av[1]);
	if (size_charset < 2)
	{
		bsm_putstr("syntax error", 2);
		return (0);
	}
	if (!(*charset = malloc(sizeof(char) * size_charset + 1)))
	{
		bsm_putstr("syntax error", 2);
		return (0);
	}
	bsm_strncpy(*charset, av[1], size_charset);
	if (charset_invalid(*charset) || has_repeat_characters(*charset))
		return (0);
	return (1);
}

/*
** read an infix arithmetic expression from stdin.
*/

int			bsm_read_stdin(char **arith_expr, char *charset, int expr_len)
{
	ssize_t	nread;

	if (!(*arith_expr = malloc(sizeof(char) * expr_len + 1)))
	{
		bsm_putstr("syntax error", 2);
		return (1);
	}
	nread = read(0, *arith_expr, expr_len);
	if ((nread <= 1 && (*arith_expr)[nread - 1] == '\n') || nread == 0)
		return (1);
	if ((*arith_expr)[nread - 1] == '\n')
		(*arith_expr)[nread - 1] = '\0';
	else
		(*arith_expr)[nread] = '\0';
	if (arith_expr_invalid(*arith_expr, charset, expr_len))
		return (1);
	return (0);
}
