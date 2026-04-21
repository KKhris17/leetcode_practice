# Count Submatrices With Equal Frequency of X and Y

## Problem
Given 2D matrix array named 'grid', where each cell (grid[i][j]) contains either 'X', 'Y' or '.'
Return numbers of sub-matrix that 
- start at [0][0]
- contain equal number of 'X' and 'Y',
- contain at least one 'X'

## Idea
Replace 'X' with 1, 'Y' with -1,and '.' with 0. Then, if the sum of sub-matrix value is 0,
it means numbers of 'X' cells equal to the number of 'Y' cells. But this condition alone is not sufficient ('.' all cell case).
Therefore, need to check wheter the sub-matrix contrains at least one 'X'. Since all valid submatrices start from [0][0], 
a '2D prefix-sum method' used to easily calculate sum of sub-matrix.

## Approach
- Allocate memmory for two new matrix:
	- 'intgrid', a converted matrix, Don't forgot to Free!
	- 'prefix', used to store prefix sum values and wheter an 'X' has been found.
- Convert each cell and store it in 'intgrid': 
	- 'X'=1
	- 'Y'=-1
	- '.'=0 
- Initialize the frist element 'prefix[0][0]', the frist row 'prefix[i][0]', and the first column  'prefix[0][j]'
- 2D prefix-sum method to chcek whether:
	- the sub-matrix sum is 0
	- at least one 'X' has been found

## Complexity
- Time Complexity : O(n * m) / (O(row * col)) ~ O(n^2)
- Space Complexity : O(n * m) / 2 matrix

## Record
- Runtime 67 ms, Beats 6.90% (19/03/26)
- Memory 87.69 MB, Beats 10.34% (19/03/26)

## Example
- input: grid = [["X","Y","."],["Y",".","."]]
- output: 3 -> [["X","Y"]], [["X","Y","."]], [["X"],["Y"]]

## AI Usage
AI assistance was used in this practice for:
- understanding concepts and technical terms
- preliminary research
- langauge translation
- identifying possible root cause of bugs

**AI was not used to directly generate the code.**