class Solution {
public:
    int climbStairs(int n) {
        int r[50] = {0};
        int f[50] = {0};
        r[1] = 1;
        r[2] = 2;
        r[3] = 3;
        if(n==1)
            return r[1];
        if(n==2)
            return r[2];
        for(int i = 3;i<=n;i++)
            r[i] = r[i-1] + r[i-2];
        return r[n];
    }
};
