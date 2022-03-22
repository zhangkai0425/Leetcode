class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int cnt[501] = {0};
        bool flag = true;
        for(auto a:nums)
            cnt[a] += 1;
        for(int i=0;i<500;i++)
            if(cnt[i]%2==1)
                flag = false;
        return flag;
    }
};
