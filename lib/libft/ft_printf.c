/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:57:44 by amarna            #+#    #+#             */
/*   Updated: 2022/06/07 15:24:34 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_ptr_to_hexa(va_list arg, int *len)
{
	unsigned long	p;

	p = va_arg(arg, unsigned long);
	if ((void *)p == NULL)
		ft_putstr(PTR_NULL, len);
	else
	{
		ft_putstr("0x", len);
		ft_putnbr_base_hex_ptr(p, "0123456789abcdef", len);
	}
}

static void	put_s(va_list arg, int *len)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s == NULL)
		ft_putstr("(null)", len);
	else
		ft_putstr(s, len);
}

static void	check_format(const char *str, va_list arg, int index, int *len)
{
	if (str[index] == 'c')
		ft_putchar((char)va_arg(arg, int), len);
	if (str[index] == 's')
		put_s(arg, len);
	if (str[index] == 'd')
		ft_putnbr(va_arg(arg, int), len);
	if (str[index] == 'i')
		ft_putnbr(va_arg(arg, int), len);
	if (str[index] == 'u')
		ft_putnbr_u(va_arg(arg, unsigned int), len);
	if (str[index] == 'x')
		ft_putnbr_base_hex(va_arg(arg, unsigned int), "0123456789abcdef", len);
	if (str[index] == 'X')
		ft_putnbr_base_hex(va_arg(arg, unsigned int), "0123456789ABCDEF", len);
	if (str[index] == '%')
		*len += write(1, "%", 1);
	if (str[index] == 'p')
		put_ptr_to_hexa(arg, len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_format(format, ap, i, &len);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
