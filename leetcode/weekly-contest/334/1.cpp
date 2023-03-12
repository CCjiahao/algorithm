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
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size() - 1; i++) left[i + 1] = left[i] + nums[i];
        for(int i = nums.size() - 1; i > 0; i--) right[i - 1] = right[i] + nums[i];
        for(int i = 0; i < nums.size(); i++) ans[i] = abs(left[i] - right[i]);
        return ans;
    }
};

int main() {
    Solution solution;


    return 0;
}