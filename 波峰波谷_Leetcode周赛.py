class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        # TODO:合并同类波峰波谷
        newnums = []
        for i in range(0,len(nums)-1):
            if nums[i]==nums[i+1]:
                continue
            else:
                newnums.append(nums[i])
        newnums.append(nums[-1])
        if len(newnums)==1 or len(newnums)==2:
            return 0   
        HV = 0
        for i in range(1,len(newnums)-1):
            if (newnums[i-1]-newnums[i])*(newnums[i+1]-newnums[i])>0:
                HV += 1
        return HV
