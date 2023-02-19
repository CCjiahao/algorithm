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
    int ti(int num, int a, int b) {
        int ans = 0, w = 1;
        while(num) {
            if(num % 10 == a) ans = w * b + ans;
            else ans = w * (num % 10) + ans;
            num /= 10;
            w *= 10;
        }
        return ans;
    }

    int minMaxDifference(int num) {
        int mx = 0, mi = INT_MAX;
        for(int i = 0; i < 10; i++) mx = max(mx, ti(num, i, 9));
        for(int i = 0; i < 10; i++) mi = min(mi, ti(num, i, 0));
        return mx - mi;
    }
};

int main() {
    Solution solution;
    solution.minMaxDifference(90);

    return 0;
}