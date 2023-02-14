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
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<int> pre(prizePositions.size() + 1, 0);
        int ans = 0, left = 0, right = 0;
        for(int right = 0; right < prizePositions.size(); right++) {
            while(prizePositions[right] - prizePositions[left] > k) left++;
            int now = right - left + 1;
            pre[right + 1] = max(pre[right], now);
            ans = max(ans, now + pre[left]);
        }
        return ans;
    }
};

int main() {
    Solution solution;


    return 0;
}