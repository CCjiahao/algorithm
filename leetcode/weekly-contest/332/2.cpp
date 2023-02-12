#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int lower_index = nums.size() - 1, upper_index = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
            while(lower_index > i && nums[i] + nums[lower_index] >= lower) lower_index--;
            while(upper_index > i && nums[i] + nums[upper_index] > upper) upper_index--;
            if(lower_index > i) ans += upper_index - lower_index;
            else if(upper_index > i) ans += upper_index - i;
        }
        return ans;
    }
};

int main() {
    return 0;
}