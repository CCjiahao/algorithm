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
        if(i == 0) cout << "[";
        cout << list[i];
        if(i == list.size() - 1) cout << "]";
        else cout << ",";
    }
    if(endline) cout << endl;
}

template <typename T>
void print_2_vector(vector<T> list) {
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) cout << "[";
        print_vector(list[i], false);
        if(i == list.size() - 1) cout << "]";
        else cout << ",";
    }
}

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int, pair<int, int>> mp;
        for(int i = 0; i < s.length(); i++) {
            int now = 0;
            for(int j = 0; i + j < s.length() && j < 30; j++) {
                now = now * 2 + s[i + j] - '0';
                if(!mp.count(now)) mp[now] = {i, i + j};
                if(s[i] == '0') break;
            }
        }
        vector<vector<int>> ans;
        for(const auto& query : queries) {
            int q = query[0] ^ query[1];
            if(mp.count(q)) ans.push_back({mp[q].first, mp[q].second});
            else ans.push_back({-1, -1});
        }
        return ans;
    }
};

int main() {
    Solution solution;

    auto queries = make_2_vector({{0, 5}, {1, 2}});
    auto ans = solution.substringXorQueries("101101", queries);

    print_2_vector(ans);

    return 0;
}