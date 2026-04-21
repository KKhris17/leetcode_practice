# Count Submatrices with Top-Left Element and Sum Less Than k

## Problem
Given a 2D grid of intergers and an integer k, count the number of submatrices that contain the top-left element and have a sum less than or equal to k.

## Idea
Use a 2D prefix sum method  to efficiently calculate the sum of any submatrix that includes the top-left element. 

	The prefix sum formula:
		prefix[i][j] = grid[i][j]
					+ prefix[i-1][j]
					+ prefix[i][j-1]
					- prefix[i-1][j-1]

If prefix[i][j] <= k, count it as a valid submatrix

## Approach
- Allocate a 2D prefix sum with molloc.
- Initialixze prifix[0][0], first row, and first column.
- Iterate through the remaining cell to complete prefix sum array.
- count cell that prefix[i][j] <= k
- Free all allocated memory before retuning.

## Complexity
- Time Complexity : O(m*n), iterate through every cell once
- Space Complexity : O(m*n), 2D prefix sum array

## Record
- Runtime 23 ms, Beats 28.57% (18/03/26)
- Memory 59.33 MB, Beats 00.00% (18/03/26)

## Example
- input 
- output 

## AI Usage
AI assistance was used in this practice for:
- understanding concepts and technical terms
- preliminary research
- langauge translation
- identifying possible root cause of bugs

**AI was not used to directly generate the code.**