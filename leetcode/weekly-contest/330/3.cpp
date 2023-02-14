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
    long long putMarbles(vector<int>& weights, int k) {
        long long MAX = weights[0] + weights[weights.size() - 1], MIN = weights[0] + weights[weights.size() - 1];
        vector<int> ve;
        for(int i = 0; i < weights.size() - 1; i++) ve.push_back(weights[i] + weights[i + 1]);
        sort(ve.begin(), ve.end(), greater<int>());
        for(int i = 0; i < k - 1; i++) MAX += ve[i];
        for(int i = 0; i < k - 1; i++) MIN += ve[ve.size() - i - 1];
        return MAX - MIN;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({1,3,5,1});

    cout <<  solution.putMarbles(a, 2);

    return 0;
}