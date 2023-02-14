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

int few[4010][4010], more[4010][4010];
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) for (int j = 0; j <= nums.size(); j++) few[i][j] = more[i][j] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 1; j <= nums.size(); j++) {
                if(nums[i] < j) few[i + 1][j] = few[i][j] + 1;
                else few[i + 1][j] = few[i][j];
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int j = 1; j <= nums.size(); j++) {
                if(nums[i] > j) more[i][j] = more[i + 1][j] + 1;
                else more[i][j] = more[i + 1][j];
            }
        }
        long long ans = 0;
        for(int i = 1; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                if(nums[i] < nums[j]) continue;
                ans += few[i][nums[j]] * more[j + 1][nums[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({1,7,6,5,8,3,2,4});
    solution.countQuadruplets(a);

    return 0;
}