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
    bool check(vector<int>& ids, int mid, int k) {
        int now = 0, ans = 0;
        for(int i = 0; i < ids.size(); i++) {
            if(ids[i] <= mid) now++;
            else {
                ans += now / 2;
                now = 0;
            }
        }
        ans += now / 2;
        return mid - ans + 1 >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        vector<int> ids;
        for(int i = 0; i < nums.size(); i++) ids.push_back(i);
        sort(ids.begin(), ids.end(), [&](const int a, const int b){return nums[a] < nums[b];});
        vector<int> ids2(ids);
        for(int i = 0; i < ids.size(); i++) ids2[ids[i]] = i;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {  //
            int mid = (left + right) / 2;
            if(check(ids2, mid, k)) right = mid - 1;
            else left = mid + 1;
        }
        sort(nums.begin(), nums.end());
        return nums[left];
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({35,9,18,78,40,8,71,2,59});
    cout << solution.minCapability(a, 5);
    return 0;
}