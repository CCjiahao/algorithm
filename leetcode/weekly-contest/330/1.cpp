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
    int distinctIntegers(int n) {
        bool vis[110] = {0};
        vis[n] = true;
        while(true) {
            bool flag = false;
            for(int i = 2; i < n; i++) {
                if(vis[i]) continue;
                for(int j = i + 1; j <= n; j++) {
                    if(vis[j] && j % i == 1) {
                        vis[i] = true;
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) if(vis[i]) ans++;
        return ans;
    }
};

int main() {
    Solution solution;
    solution.distinctIntegers(5);

    return 0;
}