/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix_row.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:25:22 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 15:12:19 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		row_left_num(int (*matrix)[4], int row)
{
	int col;
	int max;
	int count;

	max = matrix[row][0];
	col = 1;
	count = 1;
	while (col < 4)
	{
		if (max < matrix[row][col])
		{
			max = matrix[row][col];
			++count;
		}
		++col;
	}
	return (count);
}

int		row_right_num(int (*matrix)[4], int row)
{
	int col;
	int max;
	int count;

	max = matrix[row][3];
	col = 3;
	count = 1;
	while (col >= 0)
	{
		if (max < matrix[row][col])
		{
			max = matrix[row][col];
			++count;
		}
		--col;
	}
	return (count);
}

int		check_row(int (*matrix)[4], int *input, int row)
{
	int left;
	int right;
	int left_count;
	int right_count;

	left = input[row + 8];
	right = input[row + 12];
	left_count = row_left_num(matrix, row);
	right_count = row_right_num(matrix, row);
	if (left != left_count || right != right_count)
		return (0);
	return (1);
}
