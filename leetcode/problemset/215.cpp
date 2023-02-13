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
    template <typename T>
    T topk_by_qsort(vector<T>&nums, int begin, int end, int k) {
        auto& base = nums[begin];
        int l = begin, r = end;
        while(l < r) {
            while(l < r && nums[r] <= base) r--;
            while(l < r && nums[l] >= base) l++;
            swap(nums[l], nums[r]);
        }
        swap(base, nums[l]);
        if(l == k - 1) return nums[l];
        if(l > k - 1) return topk_by_qsort(nums, begin, l - 1, k);
        return topk_by_qsort(nums, l + 1, end, k);
    }
    
    template <typename T>
    T topk(vector<T>&nums, int k) {
        return topk_by_qsort<T>(nums, 0, nums.size() - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return topk(nums, k);
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({3,2,1,5,6,4});
    cout << solution.findKthLargest(a, 2) << endl;

    return 0;
}