class Solution:
	def maxDistance(self, colors: List[int]) -> int:
		last_idx = len(colors) - 1
		max_dist = 0
		left = 0
		right = last_idx
		
		while ((right > 0) and (colors[0] == colors[right])):
			right -= 1
		max_dist = right - 0
		
		while ((max_dist > (last_idx - left)) and (colors[left] == colors[last_idx])):
			left += 1
			
		if ((last_idx - left) > max_dist):
			max_dist = last_idx - left
		return (max_dist)    
        