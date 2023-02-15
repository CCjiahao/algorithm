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

int dp[1010];
int pre[1010][1010];
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            pre[i][i] = k;
            unordered_map<int, int> mp; mp[nums[i]] = 1;
            for(int j = i + 1; j < nums.size(); j++) {
                if(!mp.count(nums[j])) pre[i][j] = pre[i][j-1];
                else if (mp[nums[j]] == 1) pre[i][j] = pre[i][j-1] + 2;
                else pre[i][j] = pre[i][j-1] + 1;
                mp[nums[j]]++;
            }
        }

        dp[0] = 0, dp[1] = k;
        for(int i = 1; i < nums.size(); i++) {
            dp[i + 1] = dp[i] + k;
            for(int j = 0; j <= i; j++) {
                dp[i + 1] = min(dp[i + 1], dp[j] + pre[j][i]);
            }
        }
        return dp[nums.size()];
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({1,2,1,2,1});
    solution.minCost(a, 5);

    return 0;
}