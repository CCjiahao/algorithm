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
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        priority_queue<pair<int, pair<int, int>>> qu;
        qu.push({0, {0, 0}});
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!qu.empty()) {
            auto now = qu.top(); qu.pop();
            if(vis[now.second.first][now.second.second]) continue;
            vis[now.second.first][now.second.second] = 1;
            if(now.second.first == grid.size() - 1 && now.second.second == grid[0].size() - 1) return -now.first;

            for(int i = 0; i < 4; i++) {
                int nx = now.second.first + dx[i];
                int ny = now.second.second + dy[i];
                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                if(vis[nx][ny]) continue;
                if(-now.first + 1 >= grid[nx][ny]) qu.push({now.first-1, {nx, ny}});
                else if((grid[nx][ny] - (-now.first + 1)) % 2 == 0) qu.push({-grid[nx][ny], {nx, ny}});
                else qu.push({-grid[nx][ny] - 1, {nx, ny}});
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;


    return 0;
}