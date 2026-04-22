/**
 * Note: The returned array must be malloced, assume caller calls free().
 * queriesSize, dictionarySize, returnSize equire knowing how many words are in an array.”
 */

#include <string.h>

char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) 
{
    int		queries_ssize[queriesSize];
	int		queries_status[queriesSize];
	int		dict_ssize[dictionarySize];
	int		q_idx = 0;
	int		d_idx = 0;
	int		t_idx = 0;
	int		i = 0;
	int		edit_count = 0;
	char**	output;

	memset(queries_status, 0, queriesSize*(sizeof(int))); // memset(pointer, value, btye)
	while (q_idx < queriesSize)
	{
		i = 0;
		while (queries[q_idx][i] != '\0')
			i++;
		queries_ssize[q_idx] = i;
		q_idx++;
	}
	q_idx = 0;
	i = 0;
	while (d_idx < dictionarySize)
	{
		i = 0;
		while (dictionary[d_idx][i] != '\0')
			i++;
		dict_ssize[d_idx] = i;
		d_idx++;
	}
	d_idx = 0;
	i = 0;
	while (q_idx < queriesSize)
	{
		d_idx = 0;
		while (d_idx < dictionarySize)
		{
			edit_count = 0;
			i = 0;
			if (queries_ssize[q_idx] == dict_ssize[d_idx])
			{
				while(queries[q_idx][i] != '\0')
				{
					if (queries[q_idx][i] != dictionary[d_idx][i])
						edit_count++;
					if (edit_count > 2)
						break;
					if (queries[q_idx][i+1] == '\0')
						queries_status[q_idx] = 1;
					i++;
				}
			}
			d_idx++;
		}
		q_idx++;
	}
	*returnSize = 0;
	q_idx = 0;
	while (q_idx < queriesSize)
	{
		if (queries_status[q_idx] == 1)
			(*returnSize)++;
		q_idx++;
	}
	if ((*returnSize) == 0)
		return (NULL);
	output = (char **)malloc((*returnSize) * sizeof(char *));
	if (!output)
		return (NULL);
	i = 0;
	q_idx = 0;
	//จะmalloc หรือ ชี้ไปที่ pointer ที่รับเข้าก็ได้
	while (i < (*returnSize))
	{
		while(q_idx < queriesSize)
		{
			if (queries_status[q_idx] == 1)
				break;
			q_idx++;
		}
		output[i] = queries[q_idx];
		i++;
		q_idx++;
	}
	return (output);
}