/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:06:17 by dpearson          #+#    #+#             */
/*   Updated: 2018/01/15 13:46:15 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include <stdlib.h>
# define MAX(X,Y) ((X > Y) ? X : Y)

typedef struct	s_operations
{
	int			base;
	const char	*charset;
	int			*result;
	int			max_len;
	int			res_len;
	char		*str1;
	char		*str2;
	char		*mod;
	int			mod_tag;
	int			num1;
	int			num2;
	int			len1;
	int			len2;
	int			neg;
	int			carry;
	int			sum;
	int			i_str1;
	int			i_str2;
	int			i;
	int			j;
}				t_ops;

char			*bsm_intarr_to_str(int *result, int len, int rev,
					const char *charset);
char			*bsm_subarr_to_str(int *result, int len, const char *charset);
int				is_bigger(char *big, char *small, const char *charset);
int				negative_handle(t_ops *ops);
int				index_char(char c, const char *charset);
char			*dispatch(char *str1, char *str2, char op, const char *charset);
char			*op_sub(t_ops *ops);
char			*op_mul(t_ops *ops);
char			*op_div(t_ops *ops);
char			*op_mod(t_ops *ops);
char			*op_add(t_ops *ops);
#endif
