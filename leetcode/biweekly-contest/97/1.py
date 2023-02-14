class Solution(object):
    def separateDigits(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [int(x) for num in nums for x in str(num)]


s = Solution()
b = s.separateDigits([13,25,83,77])
pass
