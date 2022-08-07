class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0,j = nums.size()-1,mid;
        if(nums[i]<nums[j]) return nums[0];
        while(i<j){
            mid = (i + j)>>1;
            if(nums[mid]>=nums[i]&&nums[mid]>=nums[j]) i = mid + 1;
            else j = mid;
        }
        return nums[i];
    }
};
