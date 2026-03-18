#	Concatenation of Array

## Problem
Given an interger array 'input' of lenght 'n' need return array 'output'that length '2n' that
- output[i] = input[i] ;  0<>=i<n
- output[i+n] = input[i] ;  0<>=i<n

## Idea
Create new array of size '2n' and copy the element by one while loop with 2 copy in the same loop 'output[i] and output[i+n]'.

## Approach
- Create new array allocate the memory by malloc (assume caller calls free()).
- Iterate through the original array once by while loop with iterator(i).
- For each element make to copy.
	- copy into 'output[i]'.
	- copy into 'output[i+n]'.

## Complexity
- Time Complexity : O(n), iterate through the array once.
- Space Complexity : O(n), allcated '2n'

## Record
- Runtime 0ms
- Memory 15.1 MB

## Example
- input [1,2,3]
- output [1,2,3,1,2,3]

