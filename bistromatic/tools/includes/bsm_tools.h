/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:59:11 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/10 20:59:29 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSM_TOOLS_H
# define BSM_TOOLS_H

# include <unistd.h>
# include <stdlib.h>

size_t	bsm_strlen(const char *s);
char	*bsm_strncpy(char *dst, const char *src, size_t n);
char	*bsm_strnew(size_t size);
void	*bsm_memcpy(void *dst, const void *src, size_t n);
void	*bsm_memalloc(size_t size);
void	bsm_putstr(const char *s, int fd);
char	*bsm_strchr(const char *s, char c);
int		bsm_atoi(const char *addr);
int		bsm_strequ(char *s1, char *s2);
char	*remove_neg(char *str);
char	*add_neg(char *str);
#endif
