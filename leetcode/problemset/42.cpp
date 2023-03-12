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
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int ans = 0;
        for(int i = 1; i < height.size(); i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int mid = height[st.top()]; st.pop();
                if(st.empty()) break;
                int last = st.top();
                ans += (i - last - 1) * (min(height[i], height[last]) - mid);
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({0,1,0,2,1,0,1,3,2,1,2,1});
    solution.trap(a);
    return 0;
}