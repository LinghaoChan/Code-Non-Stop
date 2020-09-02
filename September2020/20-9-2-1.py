class Solution(object):
    def removeDuplicates(self, nums):
        nums[:] = sorted(list(set(nums)))
        return len(nums)