/*
Count Submatrices with Top-Left Element and Sum Less Than k
Constraints:

m == grid.length 
n == grid[i].length
1 <= n, m <= 1000 
0 <= grid[i][j] <= 1000
1 <= k <= 10^9
*/

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int	i = 0;//for gridSize (Row counter,y)
	int j = 0;//for gridColSize (Col counter,x)
	int	sum;
	int	output = 0;
	int	max_row = 1;
	int	max_col = 1;

	//Row is the Main variable to  observe sub-matrix via max_row loop
	while (max_row < gridSize + 1)
	{
		sum = 0;
	
		while (max_col < *gridColSize + 1)
		{
			while (i < max_row)
			{
				sum += grid[i][j];
				i++; //move interator before break to prevent infinite-loop
				if (sum > k)
					break;
			j++;
			max_col++;
			if (sum > k)
			{
				j = 0;
				break;
			}
			output++;
		}
		max_row++;
	}
	}
	return (output);
}
