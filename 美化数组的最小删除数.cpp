class Solution {
public:
    int minDeletion(vector<int>& nums) {
        //贪心算法+flag 确定当前奇偶/不真正删除元素/只O(n)复杂度
        auto size = nums.size();
        bool flag = true;
        int i = 0;
        int cnt = 0;
        while(i<size-1){
            if(flag&&i%2==0&&nums[i]==nums[i+1]){
                //删除当前数,之后的下标奇偶转换
                i++;
                cnt ++;
                flag = !flag;
                continue;
            }
            if(!flag&&i%2==1&&nums[i]==nums[i+1]){
                i++;
                cnt++;
                flag = !flag;
                continue;
            }
            i++;
        }
        if((size-cnt)%2==1)
            cnt ++;
        return cnt;
    }
};
