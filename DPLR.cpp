#include<iostream>
#include<vector>
using namespace std;
int maxPathSum(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    int dpL[m][n],dpR[m][n],dp[m][n]; //一个代表左走,一个代表右走,一个代表最终的(即考虑左右两种情况)
    memset(dpL,0,sizeof(dpL));
    memset(dpR,0,sizeof(dpR));
    memset(dp,0,sizeof(dp));
    for(int j=0;j<n;j++)
        dp[0][j] = grid[0][j],dpL[0][j] = grid[0][j],dpR[0][j] = grid[0][j];
    for(int i=1;i<m;i++){
        //假设到每一行左走
        for(int j=n-1;j>=0;j--)
            if(j==(n-1))
                dpL[i][j] = dp[i-1][j] + grid[i][j]; //最右列的特殊情况
            else
                dpL[i][j] = max(dp[i-1][j],dpL[i][j+1]) + grid[i][j];
        //假设到每一行右走
        for(int j=0;j<n;j++)
            if(j==0)
                dpR[i][j] = dp[i-1][j] + grid[i][j]; //第一列的特殊情况
            else
                dpR[i][j] = max(dp[i-1][j],dpR[i][j-1]) + grid[i][j];
        //综合考虑两种情况
        for(int j=0;j<n;j++)
            dp[i][j] = max(dpL[i][j], dpR[i][j]);
    }
    auto v = dp[m-1]; //取出来最后一行,返回最大值即可
    return *max_element(v,v+n);
}
int main(){
    //示例2:不写输入输出了
    vector<vector<int>> grid = {{0,0,0,0},{1,-5,20,3},{3,2,-50,20},{3,3,3,3},{9,-100,0,17}};
    auto ans = maxPathSum(grid);
    cout<<"ans = "<<ans<<endl;
}
