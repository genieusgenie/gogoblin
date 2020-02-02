/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:25:33 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 15:09:52 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_arr[24][4];

int		col_up_num(int ith)
{
	int row;
	int max;
	int count;

	row = 1;
	count = 1;
	max = g_arr[ith][0];
	while (row < 4)
	{
		if (max < g_arr[ith][row])
		{
			max = g_arr[ith][row];
			++count;
		}
		++row;
	}
	return (count);
}

int		col_down_num(int ith)
{
	int row;
	int max;
	int count;

	row = 2;
	count = 1;
	max = g_arr[ith][3];
	while (row >= 0)
	{
		if (max < g_arr[ith][row])
		{
			max = g_arr[ith][row];
			++count;
		}
		--row;
	}
	return (count);
}

int		check_col(int *input, int col, int ith)
{
	int up;
	int down;
	int up_count;
	int down_count;

	up = input[col];
	down = input[col + 4];
	up_count = col_up_num(ith);
	down_count = col_down_num(ith);
	if (up != up_count || down != down_count)
		return (0);
	return (1);
}
