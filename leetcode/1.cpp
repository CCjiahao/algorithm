#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) mp[target - nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]) && i != mp[nums[i]]) {
                ans.push_back(i);
                ans.push_back(mp[nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}