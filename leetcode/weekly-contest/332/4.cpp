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
    int minimumScore(string s, string t) {
        vector<int> l(s.length(), 0);
        l[0] = s[0] == t[0];
        for(int i = 1; i < s.length(); i++) {
            if(l[i - 1] < t.length() && t[l[i - 1]] == s[i]) l[i] = l[i - 1] + 1;
            else l[i]= l[i - 1];
        }
        vector<int> r(s.length(), 0);
        r[s.length() - 1] = s[s.length() - 1] == t[t.length() - 1];
        for(int i = s.length() - 2; i >= 0; i--) {
            if(r[i + 1] < t.length() && t[t.length() - r[i + 1] - 1] == s[i]) r[i] = r[i + 1] + 1;
            else r[i]= r[i + 1];
        }
        int ans = max(r[0], l[s.length() - 1]);
        for(int i = 0; i < s.length() - 1; i++) {
            ans = max(ans, min(l[i] + r[i + 1], (int)t.length()));
        } 
        return t.length() - ans;
    }
};


int main() {
    Solution solution;
    cout << solution.minimumScore("adebddaccdcabaade", "adbae") << endl;

    return 0;
}