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
    long long pickGifts(vector<int>& gifts, int k) {
        map<int, int> mp;
        for(auto& gift : gifts) mp[-gift]++;
        while(k--) {
            int key = -mp.begin()->first;
            mp[-key]--;
            if(mp[-key] == 0) mp.erase(-key);
            mp[-(int)sqrt(key)]++;
        }
        long long ans = 0;
        for(auto& p : mp) ans -= p.first * p.second;
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({1, 1, 1, 1});
    cout << solution.pickGifts(a, 4);

    return 0;
}