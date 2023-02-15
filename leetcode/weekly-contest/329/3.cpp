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
    bool makeStringsEqual(string s, string target) {
        if(s == target) return true;
        bool flag = true;
        for(int i = 0; i < target.size(); i++) if(target[i] == '1') flag = false;
        if(flag) return false;
        flag = true;
        for(int i = 0; i < s.size(); i++) if(s[i] == '1') flag = false;
        if(flag) return false;
        return true;
    }
};

int main() {
    Solution solution;


    return 0;
}