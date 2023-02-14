class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """
        ans = 0
        banned = set(banned)
        for i in range(1, n + 1):
            if i > maxSum:
                break
            if i not in banned:
                maxSum -= i
                ans += 1
        return ans