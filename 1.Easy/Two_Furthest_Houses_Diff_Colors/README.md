# Two Furthest Houses With Different Colors

## Problem
Find the maximum distance (index) between the intergers in an interger array that represents colors.
	Constraints:
	- n == colors.length
	- 2 <= n <= 100
	- 0 <= colors[i] <= 100

## Idea
### Version 1 (Initial)
Start from the left-most index(left), pair it with the right most index (right). If they differ, store the distance (right - left) in max_distance, then increment left. If not, decrement right until a difference color is found. Repeat until (len - 1) - i < max_distance.

After research, this approach was found to be O(n²) dur to resettinh right in every iteraiton of left

### Version 2 (Optimized)
Use 2 independent passes (loop) instead, since the maximum distance must have at least one value either the left-most or right-most index.
- Pass 1: Fix left = 0, walk right inward until a difference is found.
- Pass 2: Fix right = last index, walk left inward until a difference is found.
- Answer = max(Pass1, Pass 2)

## Complexity
- Time Complexity : O(n)
- Space Complexity : O(1)

## Record
- c_version (20/04/26)
	- Runtime 0ms
	- Memory 8.89 MB (Beats 31.94%)
- py_version (21/04/26)
	- Runtime 0ms
	- Memory 19.37 MB (Beats 25.06%)

## Example
- input [**1**,1,1,**6**,1,1,1]
- output 3

## AI Usage
AI assistance was used in this practice for:
- discus for performance improvement
- langauge translation

**AI was not used to directly generate the code.**