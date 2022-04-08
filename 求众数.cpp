class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mydict;
        unordered_map<int,int>visit;
        vector<int>ans;
        int n = nums.size();
        for(auto i:nums){
            mydict[i]++;
            if(mydict[i]>n/3&&!visit[i]){
                ans.push_back(i);
                visit[i] = 1;
            }
        }
        return ans;
    }
};
