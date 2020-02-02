/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:26:28 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 15:13:48 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_row(int (*matrix)[4], int *input, int row);

int		is_same_num_exist(int (*matrix)[4], int row)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (matrix[row][i] == matrix[row][j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int		check_matrix(int (*matrix)[4], int *input)
{
	int row;

	row = 0;
	while (row < 4)
	{
		if (!check_row(matrix, input, row))
			return (0);
		if (is_same_num_exist(matrix, row))
			return (0);
		++row;
	}
	return (1);
}
