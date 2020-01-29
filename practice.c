/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:48:20 by sooyoon           #+#    #+#             */
/*   Updated: 2020/01/29 14:20:36 by sooyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_i = 0;

void	ifif(int i);
void	putchar(char c);
void	print(int *t, int n);

void	ft_print_combn(int n)
{
	int tab[n];

	if (n == 1)
		ifif(g_i);
	while (g_i < n)
	{
		tab[g_i] = 0;
		g_i++;
	}
	while (tab[0] <= (10 - n) && n > 1)
	{
		print(tab, n);
		tab[n - 1]++;
		g_i = n;
		while (g_i && n > 1)
		{
			g_i--;
			if (tab[g_i] > 9)
			{
				tab[g_i - 1]++;
				tab[g_i] = 0;
			}
		}
	}
}

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *t, int n)
{
	int i;
	int islower;

	i = 1;
	islower = 1;
	while (i < n)
	{
		if (t[i-1] >= t[i])
			islower = 0;
		i++;
	}
	if (islower)
	{
		i = 0;
		while (i < n)
			putchar(t[i++] + '0');
		if (t[0] < (10 - n))
			write(1, ", ", 2);
	}
}

void	ifif(int i)
{
	i = 0;
	while (i < 10)
	{
		putchar(i + '0');
		if (i != 9)
			write(1, ", ", 2);
		i++;
	}
}

int	main ()
{
	ft_print_combn(8);
	return 0;
}
