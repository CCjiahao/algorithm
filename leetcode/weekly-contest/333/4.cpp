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
    string findTheString(vector<vector<int>>& lcp) {
        vector<char> ss(lcp.size(), 0);
        char now = 'a';
        for(int i = 0; i < lcp.size(); i++) {
            if(ss[i] == 0) {
                ss[i] = now;
                for(int j = i + 1; j < lcp.size(); j++) {
                    if(lcp[i][j]) ss[j] = now;
                }
                now++;
            }
        }
        if(now > 'z' + 1) return "";
        for(int i = lcp.size() - 1; i >= 0; i--) {
            for(int j = lcp.size() - 1; j >= 0; j--) {
                int now = 0;
                if(ss[i] == ss[j]) now = (i+1 < lcp.size() && j+1 < lcp.size() ? lcp[i+1][j+1] : 0) + 1;
                if(now != lcp[i][j] || now != lcp[j][i]) 
                    return "";
            }
        }
        string ans = "";
        for(auto c : ss) ans += c;
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = make_2_vector({{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}});
    solution.findTheString(a);


    return 0;
}