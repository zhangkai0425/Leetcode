class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for (int i = 0,start = 0; i < s.size(); i++) 
        {
            if (s[i] == '(') st.push(i);    //左括号入栈            
            else 
            {
                if (!st.empty()) 
                {
                    st.pop();	//匹配成功
                    if (st.empty()) ans = max(ans, i - start + 1);
                    else  ans = max(ans, i - st.top()); //i - st.top() + 1 - 1
                }
                else  start = i + 1;  //更新起点                      
            }
        }
        return ans;
    }
};
