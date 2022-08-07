class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1,mid;
        while(i<j){
            mid = (i + j) >> 1;
            if(nums[mid]<nums[mid+1])
            //说明右侧必定存在峰值，不妨考虑最差情况，单调递增，则最后一个元素必然是峰值
                i = mid + 1;
            else
            //说明左侧必定存在峰值，不妨考虑最差情况，单调递减，则第一个元素必然是峰值
                j = mid;
        }
        return i;
    }
};
