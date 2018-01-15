/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:26:01 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/15 15:31:33 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"
#include "ops.h"

int	main(int ac, char **av)
{
	int		stdin_len;
	char	*charset;
	char	*infix_arith_expr;
	char	*rpn_arith_expr;
	int		i;

	if (!bsm_parse_commandline_args(ac, av, &stdin_len, &charset))
		return (1);
	if ((i = bsm_read_stdin(&infix_arith_expr, charset, stdin_len)))
		return (1);
	if (!infix_arith_expr)
	{
		bsm_putstr("syntax error", 2);
		return (1);
	}
	if (!(rpn_arith_expr = bsm_infix_to_rpn(infix_arith_expr, stdin_len)))
	{
		bsm_putstr("syntax error", 2);
		return (1);
	}
	bsm_putstr(bsm_rpn_eval(rpn_arith_expr, charset), 1);
	return (0);
}
