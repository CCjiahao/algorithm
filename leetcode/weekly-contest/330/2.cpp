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
    long long qsm(long long a, long long b, long long mod=1e9+7) {
        long long ans = 1;
        while(b) {
            if(b&1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return ans;
    }

    int monkeyMove(int n) {
        return (qsm(2, n) - 2 + (int)1e9+7) % ((int)1e9+7);
    }
};

int main() {
    Solution solution;
    cout << solution.monkeyMove(55);

    return 0;
}