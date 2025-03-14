/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:37:38 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/06 11:38:47 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// HEADERS PRINTF
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
int		format_str(const char str, va_list *args);
int		ft_c_putchar(int c);
int		ft_s_putstr(const char *str);
int		ft_p_puntvoid(void *ptr);
int		ft_d_i_putint(int n);
int		ft_u_putint(unsigned int n);
int		ft_x_hexa(unsigned int n);
int		ft_xx_hexa(unsigned int n);

#endif
