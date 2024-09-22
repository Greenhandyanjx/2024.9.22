#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
        int sum = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    for (int a = 0; a < 4; a++)
                    {
                        int nextx = i + dir[a][0];
                        int nexty = j + dir[a][1];
                        if (nextx < 0 || nextx >= row || nexty < 0 || nexty >= col || grid[nextx][nexty] == 0)
                            sum++;
                    }
                }
            }
        }
        return sum;
    }
};
class Solution {
public:
    int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    int sum = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y] || grid[x][y] == 0)
        {
            return;
        }
        visited[x][y] = true;
        sum++;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())continue;
            dfs(grid, visited, nextx, nexty);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxV=0;
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    maxV = max(maxV, sum);
                    sum = 0;
                }
            }
        }
        return maxV;
    }
};
class Solution {
public:
    int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    void dfs(vector<vector<char>>& graph, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y] || graph[x][y] == '0')return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx<0 || nextx>graph.size() || nexty<0 || nexty>graph[0].size())continue;
            dfs(graph, visited, nextx, nexty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};