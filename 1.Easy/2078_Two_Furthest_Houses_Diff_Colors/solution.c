// Version 2 improve big O, O(n^2) -> O(n)
int maxDistance(int* colors, int colorsSize) {
	int last_idx = colorsSize - 1;
	int	left = 0;
	int right = last_idx;
	int	max_dist = 0;

	// if (colorsSize <= 1) // Not necessary because the constraint
	// 	return (-1);
	while ((right > 0) && (colors[0] == colors[right]))
		right--;
	max_dist = right - 0;
	while ((left < last_idx) &&(colors[left] == colors[last_idx]))
		left++;
	if ((last_idx - left) > max_dist)
		max_dist = last_idx - left;
	return max_dist;
}

// // Verision 1
// int maxDistance(int* colors, int colorsSize) {
//     int	i;
// 	int j;
// 	int	output;

// 	i = 0;
// 	j = colorsSize - 1;
// 	output = 0;
// 	while (((colorsSize - 1) - i) > output)
// 	{
// 		if (colors[i] != colors[j])
// 		{
// 			if ((j - i) > output)
// 				output = j - i;
// 			i++;
//             j = colorsSize - 1;
// 			continue;
// 		}
// 		j--;
// 	}
// 	return (output);
// }

// // Version 1.2 improves code structure and readability.
// int maxDistance(int* colors, int colorsSize) {
//     int	left = 0;
// 	int last_idx = colorsSize - 1;
// 	int right = last_idx;
// 	int	max_distance = 0;

// 	if (colorsSize <= 1) //guard clause
// 		return (-1);
// 	while ((last_idx - left) > max_distance)
// 	{
// 		right = last_idx;
// 		while (left < right)
// 		{
// 			if (colors[left] != colors[right])
// 			{
// 				if ((right - left) > max_distance)
// 					max_distance = right - left;
// 				break;
// 			}
// 			right--;
// 		}
// 		left++;
// 	}
// 	return max_distance;
// }