/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:04:29 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:56:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DECIMAL "0123456789"
# define SIGNED 1
# define UNSIGNED 0
# define UP_HEX "0123456789ABCDEF"
# define LOW_HEX "0123456789abcdef"

int		ft_speccheck(char c);
void	ft_forconversion(char c, va_list args, int *count);
void	ft_putchar_printf(char c, int *count);
void	ft_putstr_printf(char *str, int *count);
void	ft_putadd(void *add, int *count);
size_t	ft_strlen_printf(const char *str);
void	ft_putnbr_base(int nbr, int sign, char *base_set, int *count);
void	ft_putchar_base(int nbr, char *base, int *count);
int		ft_printf(const char *str, ...);

#endif
