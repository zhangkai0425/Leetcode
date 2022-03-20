class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        for(int i =0;i<12;i++)
            aliceArrows[i] += 1;
        int dp[12][numArrows+1];
        memset(dp,0,sizeof(dp));
        // vector<vector<int>> dp(12,vector<int>(numArrows+1,0));
        for(int i =1;i<12;i++)
            for(int j=1;j<numArrows+1;j++)
                {
                    //不选第i个
                    dp[i][j] = dp[i-1][j];
                    if(j>=aliceArrows[i])
                        dp[i][j] = max(dp[i][j],dp[i-1][j-aliceArrows[i]]+i);
                }
        vector<int>best(12,0);
        int m = 11;
        int bag_weight = numArrows;
        while(m>=1){
            int i = m;
            if(dp[i][bag_weight]==dp[i-1][bag_weight])
                best[i] = 0;
            else{
                best[i] = aliceArrows[i];
                bag_weight -= aliceArrows[i];
            }
            m -= 1;
        }
        int sum = 0;
        for(int i =0;i<12;i++)
            sum += best[i];
        if(sum < numArrows)
            best[0] += numArrows - sum;
        return best;
    }
};
