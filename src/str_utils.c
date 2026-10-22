/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahanlon <dahanlon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:53:50 by dahanlon          #+#    #+#             */
/*   Updated: 2026/10/17 17:53:51 by dahanlon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*mem_s1;
	const unsigned char	*mem_s2;
	size_t				i;
	int					diff;

	mem_s1 = (const unsigned char *)s1;
	mem_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && mem_s1[i] == mem_s2[i]
		&& mem_s1[i] != '\0' && mem_s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	diff = mem_s1[i] - mem_s2[i];
	return (diff);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num_char;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	num_char = (n % 10) + 48;
	write(fd, &num_char, 1);
}
