class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0]==target?0:-1;
        int l = 0,r = n - 1;
        while(l<=r){
            int mid = (l + r)>>1;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){
                //能说明l-mid肯定是有序的:充分必要条件
                if(nums[l]<=target&&target<nums[mid]) r = mid;
                else l = mid + 1;
            }
            else{
                //说明l-mid是无序的,mid-r是有序的:充分必要条件
                if(nums[mid]<target&&target<=nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
