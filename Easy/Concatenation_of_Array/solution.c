/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdlib.h>

int*	getConcatenation(int* nums, int numsSize, int* returnSize) {
	int	*output;
	int i;
	int j;

	*returnSize = 2 * numsSize;
	output = (int *)malloc((*returnSize) * sizeof(int));
	if (!output)
		return NULL;
	i = 0;
	while (i < numsSize)
	{
		output[i] = nums[i];
		output[i + numsSize] = nums[i];
		i++;
	}
	return (output);
}