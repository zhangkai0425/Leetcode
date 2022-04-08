class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n=len(grid)
        m=len(grid[0])
        count=0
        def dfs(x,y):
          for i,j in [[x+1,y],[x-1,y],[x,y+1],[x,y-1]]:
            if 0<=i<n and 0<=j<m and grid[i][j]=='1':
              # 只有搜索到陆地的时候才操作
              grid[i][j] = '0'
              dfs(i,j)
              
        for i in range(n):
            for j in range(m):
                if grid[i][j]=='1':
                    grid[i][j]='0'
                    dfs(i,j)
                    count+=1
        return count
