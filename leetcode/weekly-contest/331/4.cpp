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
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp;
        for(auto& v : basket1) mp[v]++;
        for(auto& v : basket2) mp[v]--;
        vector<int> v;
        int minn = 1e9 + 7;
        for(auto p : mp) {
            minn = min(minn, p.first);
            if(abs(p.second) % 2 != 0) return -1;
            if(p.second < 0) for(int i = p.second; i < 0; i += 2) v.push_back(p.first);
            else if(p.second > 0) for(int i = p.second; i > 0; i -= 2) v.push_back(p.first);
        }
        long long ans = 0;
        for(int i = 0; i < v.size() / 2; i++) ans += min(v[i], 2*minn);
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({5,8,15,7});
    auto b = vector<int>({5,7,8,15});
    cout << solution.minCost(a, b);
    return 0;
}