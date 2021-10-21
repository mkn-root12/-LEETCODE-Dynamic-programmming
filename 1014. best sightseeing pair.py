class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        n = len(values)
        max_pref = values[0] + 0
        ans = -float("inf")
        for i in range(1, n):
            ans = max(ans, max_pref + values[i] - i)
            max_pref = max(max_pref, values[i] + i)
        return ans
