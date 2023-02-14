#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<vector<T>> make_2_vector(initializer_list<initializer_list<T>> lists) {
    vector<vector<T>> ans;
    for(auto& list : lists) ans.push_back(vector<int>(list));
    return ans;
}

template <typename T>
void print_vector(vector<T> list, bool endline=true) {
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) cout << '[';
        cout << list[i];
        if(i == list.size() - 1) cout << ']';
        else cout << ',';
    }
    if(endline) cout << endl;
}

template <typename T>
void print_2_vector(vector<T> list) {
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) cout << '[';
        print_vector(list[i], false);
        if(i == list.size() - 1) cout << ']';
        else cout << ',';
    }
}

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis, vector<vector<int>>& vis2) {
        vis2[x][y] = true;
        if(x == grid.size() - 1 && y == grid[0].size() - 1) return true;

        static int dx[] = {1, 0, -1, 0};
        static int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] && !vis2[nx][ny]) {
                vis[nx][ny] = true;
                if(dfs(grid, nx, ny, vis, vis2)) return true;
                vis[nx][ny] = false;
            }
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), false));
        vector<vector<int>> vis2(grid.size(), vector<int>(grid[0].size(), false));
        if(!dfs(grid, 0, 0, vis, vis2)) return true;
        vis[grid.size()-1][grid[0].size()-1] = false;
        return !dfs(grid, 0, 0, vis2, vis);
    }
};

int main() {
    Solution solution;
    auto a = make_2_vector({{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0},{1,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0},{1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},{0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},{0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}});
    cout << solution.isPossibleToCutPath(a);
    return 0;
}