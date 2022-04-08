class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int>bns;
        for(int i=0;i<nums.size();i++){
            int size = ans.size();
            for(int j=0;j<size;j++){
                bns = ans[j];
                bns.push_back(nums[i]);
                ans.push_back(bns);
            }
        }
        return ans;
    }
};
