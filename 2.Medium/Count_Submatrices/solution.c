/*
Count Submatrices with Top-Left Element and Sum Less Than k
Constraints:

m == grid.length 
n == grid[i].length
1 <= n, m <= 1000 
0 <= grid[i][j] <= 1000
1 <= k <= 10^9
*/

#include <stdlib.h> // for malloc exit atoi
#include <stdio.h> // for printf when want to run main

/*2D prefix-sum method
key : prefix[i][j] = grid[i][j]
             + prefix[i-1][j]
             + prefix[i][j-1]
             - prefix[i-1][j-1]
	Previous horizontal and Previous vertical then Remove overlap
*/
int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) 
{
    int	i = 0;//for gridSize (Row counter,y) 
	int j = 0;//for gridColSize (Col counter,x)
	int	**prefix;
	int	temp;
	int	output = 0;

	prefix = malloc(gridSize * sizeof(int *));
	if (!prefix)
		return (-1);//NULL is for pointer
	while (i < gridSize)
	{
		prefix[i] = malloc(*(gridColSize) * sizeof(int));
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
	prefix[0][0] = grid[0][0];//this is reason that i,j,output=1
	if (prefix[0][0] <= k)
		output++;
	j = 1;
	temp = grid[0][0];
	while (j < *(gridColSize))
	{
		prefix[0][j] = temp + grid[0][j];
		temp = temp + grid[0][j];
		if (prefix[0][j] <= k)
			output++;
		j++;
	}
	i = 1;
	temp = grid[0][0];
	while (i < gridSize)
	{
		prefix[i][0] = temp + grid[i][0];
		temp = temp + grid[i][0];
		if (prefix[i][0] <= k)
			output++;
		i++;
	}
	i = 1;
	while (i < gridSize)
	{
		j = 1;
		while (j < *(gridColSize))
		{
			prefix[i][j] = grid[i][j] 
							+ prefix[i-1][j] + prefix[i][j-1]
							 - prefix[i-1][j-1];
			if (prefix[i][j] <= k)
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
		i++;
	}
	free (prefix);
	return (output);
}

// 	int main(void)
// {
// 	int row1[] = {7, 6, 3};
// 	int row2[] = {6, 6, 1};
// 	int *matrix[] = {row1, row2};
// 	int output;
// 	int colsize = 3;

// 	output = countSubmatrices(matrix,2,&colsize,18);
// 	printf("%d\n",output);
// 	return (0);
// }

/* Version 1 : 858/859 Time limit exceed -> O(m*n^3) ~ O(n^3)
int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int	i = 0;//for gridSize (Row counter,y)
	int	counter;
	int j = 0;//for gridColSize (Col counter,x)
	int	sum = 0;
	int	output = 0;

	//Row is the Main variable to  observe sub-matrix via max_row loop
	while (i < gridSize)
	{
		j = 0;
		sum = 0;
		while (j < *(gridColSize))
		{
			counter = 0;
			while (counter <= i)
			{
				sum += grid[counter][j];//sum in same column first
				counter++;
			}
			j++;
			if (sum > k)
				break;
			output++;
		}
		i++;
	}
	return (output);
}
}*/