#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pin(int a, int b) {
        long long w = 1, bb = b;
        while(bb) w *=10, bb /= 10;
        return w * a + b;
    }

    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int begin = 0, end = nums.size() - 1;
        while(begin <= end) {
            long long now = 0;
            if(begin == end) now = nums[begin];
            else now = pin(nums[begin], nums[end]);
            ans += now;
            begin++, end--;
        }
        return ans;
    }
};

int main() {
}