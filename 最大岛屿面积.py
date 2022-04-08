class Solution:
    area = 0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        maxarea = 0
        def dfs(x,y):
            for [i,j] in [[x-1,y],[x+1,y],[x,y-1],[x,y+1]]:
                if 0<=i<m and 0<=j<n and grid[i][j]==1:
                    grid[i][j] = 0
                    self.area += 1
                    dfs(i,j)
        for i in range(m):
            for j in range(n):
                self.area = 0
                if grid[i][j]==1:
                    grid[i][j]=0
                    self.area = 1
                    dfs(i,j)
                    maxarea = max(self.area,maxarea)
        return maxarea
