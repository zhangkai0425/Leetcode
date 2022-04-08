class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto& c:s)
            mp[c]++;
        int ans=0,f=0;
        for(auto& [_,cnt]:mp)
        //这里用括号表达式，能确保如果有奇数个数的字母，只有一次可以都加上(即放中间)，其他之后都不行
            ans+=cnt%2==0?cnt:(f=1,cnt-1); //妙啊
        return ans+f;
    }
};
