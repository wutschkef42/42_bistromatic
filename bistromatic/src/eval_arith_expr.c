/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arith_expr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:55:50 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/15 15:30:16 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"
#include "bsm_tools.h"
#include "stack.h"
#include "ops.h"

char	*bsm_eval_msign(char *operand_1)
{
	if (operand_1[0] != '-')
		return (add_neg(operand_1));
	else
		return (remove_neg(operand_1));
}

char	*bsm_neg_zero(char *str, char *charset)
{
	if (str[0] == '-' && str[1] == charset[0] && (bsm_strlen(str) == 2))
	{
		free(str);
		str = malloc(sizeof(char) * 2);
		str[0] = charset[0];
		str[1] = '\0';
		return (str);
	}
	if (str[0] == '-' && str[1] == '\0')
	{
		free(str);
		str = malloc(sizeof(char) * 2);
		str[0] = charset[0];
		str[1] = '\0';
	}
	return (str);
}

char	*bsm_strip_leading_zeros(char *result)
{
	char	*tmp;
	char	*res;
	size_t	i;

	i = 0;
	while (result[i])
	{
		if (result[i] == '0')
			i++;
		else
			break ;
	}
	if (i == bsm_strlen(result))
	{
		result[1] = '\0';
		return (result);
	}
	tmp = result;
	while (*tmp == '0')
		tmp++;
	if (!(res = malloc(sizeof(char) * bsm_strlen(result))))
		return (NULL);
	free(result);
	bsm_strncpy(res, tmp, bsm_strlen(result) - (tmp - result));
	return (res);
}

int		bsm_eval_operation(t_stack **operands, char operator,
			const char *charset)
{
	char	*operand_1;
	char	*operand_2;
	char	*result;

	if (operator == '#')
	{
		operand_1 = bsm_stack_pop(operands);
		result = bsm_eval_msign(bsm_strip_leading_zeros(operand_1));
	}
	else
	{
		operand_1 = bsm_stack_pop(operands);
		operand_2 = bsm_stack_pop(operands);
		result = dispatch(bsm_strip_leading_zeros(operand_2),
					bsm_strip_leading_zeros(operand_1), operator, charset);
	}
	if (!result)
	{
		bsm_putstr("syntax error", 2);
		return (0);
	}
	bsm_stack_push(operands, bsm_stack_new((void*)result, bsm_strlen(result)));
	return (1);
}

char	*bsm_rpn_eval(char *rpn_arith_expr, char *charset)
{
	t_stack *operands;
	char	**tokens;
	int		i;

	i = 0;
	tokens = bsm_tokenize(rpn_arith_expr);
	while (tokens[i])
	{
		if (bsm_is_operator(tokens[i][0]))
		{
			if (!bsm_eval_operation(&operands, tokens[i][0], charset))
				return (NULL);
		}
		else
			bsm_stack_push(&operands, bsm_stack_new((void*)tokens[i],
				bsm_strlen(tokens[i])));
		i++;
	}
	operands->data = bsm_neg_zero(operands->data, charset);
	return (bsm_strip_leading_zeros((char*)operands->data));
}
