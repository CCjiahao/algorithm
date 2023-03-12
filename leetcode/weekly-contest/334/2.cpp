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
    vector<int> divisibilityArray(string word, int m) {
        long long now = 0;
        vector<int> ans;
        for(int i = 0; i < word.length(); i++) {
            now = now * 10 + word[i] - '0';
            if(now >= m) now = now % m;
            if(now % m == 0) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};

int main() {
    Solution solution;


    return 0;
}