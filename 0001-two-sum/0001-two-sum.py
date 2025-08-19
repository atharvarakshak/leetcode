class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp ={}
        n = len(nums)
        for i in range(n):
            mp[nums[i]]=i

        for i in range(n):
            if((target-nums[i] in mp.keys()) and i != mp[target-nums[i]]):
                return [i, mp[target-nums[i]]]

        


