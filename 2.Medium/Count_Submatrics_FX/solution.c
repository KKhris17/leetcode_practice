/*
Count Submatrices With Equal Frequency of X and Y

submatrices that contain:
grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.

Constraints:
1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.
*/

// refer knowledge from ../Count_Submatrices

/* Hint
- Replace ’X’ with 1, ’Y’ with -1 and ’.’ with 0.
- You need to find how many submatrices grid[0..x][0..y] have a sum of 0 and at least one ’X’.
- Use prefix sum to calculate submatrices sum.*/

/*2D prefix-sum method
key : prefix[i][j] = grid[i][j]
             + prefix[i-1][j]
             + prefix[i][j-1]
             - prefix[i-1][j-1]
	Previous horizontal and Previous vertical then Remove overlap
*/

#include <stdlib.h> // for malloc exit atoi
#include <stdio.h> // for printf when want to run main

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize)
{
	typedef struct s_intWstat{
		int	value;
		int status;
	} t_intWstat; //to store value(sum) and status(found x yet?/ 1 = already found/ 0 = Not yet)

    int			i = 0;//for gridSize (Row counter,y) 
	int 		j = 0;//for gridColSize (Col counter,x)
	t_intWstat	**prefix;
	int			**intgrid; //converted matrix ('X'= 1 'Y'=-1 '.'=0)
	int			temp;//temporary variable
	int			output = 0;

	prefix = malloc(gridSize * sizeof(t_intWstat *));
	if (!prefix)
		return (-1);//NULL is for pointer
	while (i < gridSize)
	{
		prefix[i] = malloc(*(gridColSize) * sizeof(t_intWstat));
		if (!prefix[i])
		{
			temp = 0;
			while (temp < i)
			{
				free (prefix[temp]);
				temp++;
			}
			free(prefix);
			return (-1);
		}
		i++;
	}
	i = 0;
	intgrid = malloc(gridSize * sizeof(int *));
	if (!intgrid)
	{
		free (prefix);
		return (-1);//NULL is for pointer
	}
	while (i < gridSize)
	{
		intgrid[i] = malloc(*(gridColSize) * sizeof(int));
		if (!intgrid[i])
		{
			temp = 0;
			while (temp < i)
			{
				free (prefix[temp]);
				temp++;
			}
			free(prefix);
			temp = 0;
			while (temp < i)
			{
				free (intgrid[temp]);
				temp++;
			}
			free(intgrid);
			return (-1);
		}
		i++;
	}
	i = 0;

	while (i < gridSize)
	{
		j = 0;
		while (j < *(gridColSize))
		{
			if (grid[i][j] == 'X')
				intgrid[i][j] = 1;
			else if (grid[i][j] == 'Y')
				intgrid[i][j] = -1;
			else
				intgrid[i][j] = 0;
			j++;
		}
		i++;
	}
	prefix[0][0].value = intgrid[0][0];
	if (grid[0][0] == 'X')
		prefix[0][0].status = 1;
	else
		prefix[0][0].status = 0;
	j = 1;
	temp = intgrid[0][0];
	while (j < *(gridColSize))
	{
		prefix[0][j].value = temp + intgrid[0][j];
		temp = temp + intgrid[0][j];
		if (prefix[0][j - 1].status == 1)
			prefix[0][j].status = 1;
		else if (grid[0][j] == 'X')
			prefix[0][j].status = 1;
		else 
			prefix[0][j].status = 0;
		if ((prefix[0][j].value == 0) && (prefix[0][j].status == 1))
			output++;
		j++;
	}
	i = 1;
	temp = intgrid[0][0];
	while (i < gridSize)
	{
		prefix[i][0].value = temp + intgrid[i][0];
		temp = temp + intgrid[i][0];
		if (prefix[i - 1][0].status == 1)
			prefix[i][0].status = 1;
		else if (grid[i][0] == 'X')
			prefix[i][0].status = 1;
		else 
			prefix[i][0].status = 0;
		if ((prefix[i][0].value == 0) && (prefix[i][0].status == 1))
			output++;
		i++;
	}
	i = 1;
	while (i < gridSize)
	{
		j = 1;
		while (j < *(gridColSize))
		{
			prefix[i][j].value = intgrid[i][j] 
							+ prefix[i-1][j].value + prefix[i][j-1].value
							 - prefix[i-1][j-1].value;
			if (grid[i][j] == 'X')
				prefix[i][j].status = 1;
			else if (prefix[i-1][j].status == 1 || (prefix[i][j-1].status == 1) || (prefix[i-1][j-1].status == 1))
				prefix[i][j].status = 1;
			else
				prefix[i][j].status = 0;
			if ((prefix[i][j].value == 0) && (prefix[i][j].status == 1))
				output++;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < gridSize)
	{
		free(prefix[i]);
		free(intgrid[i]);
		i++;
	}
	free (prefix);
	free (intgrid);
	return (output);
}

// int main(void)
// {
// 	char row1[] = {'X', 'Y', '.'};
// 	char row2[] = {'Y', '.', '.'};
// 	char *matrix[] = {row1, row2};
// 	int output;
// 	int colsize = 3;
// 	int	gridSize = 2;

// 	output = numberOfSubmatrices(matrix,gridSize,&colsize);
// 	printf("%d\n",output);
// 	return (0);
// }
