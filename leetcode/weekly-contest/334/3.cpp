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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> bigs(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            bigs[i] = upper_bound(nums.begin(), nums.end(), nums[i]/2) - nums.begin();
        }
        int id = nums.size() - 1, ans = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(i - bigs[i] > id - bigs[id]) {
                ans += (id - i) * 2;
                id = i;
            }
        }
        ans += bigs[id] * 2;
        return min(ans, (int)nums.size()/2*2);
    }
};

int main() {
    Solution solution;
    vector<int> a = {2,4,5,9};
    // vector<int> a = {42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40};
    solution.maxNumOfMarkedIndices(a);

    return 0;
}