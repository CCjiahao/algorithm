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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre(words.size() + 1, 0);
        for(int i = 0; i < words.size(); i++) {
            pre[i + 1] = pre[i] + ((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') &&
                                   (words[i][words[i].length()-1] == 'a' || words[i][words[i].length()-1] == 'e' || words[i][words[i].length()-1] == 'i' || words[i][words[i].length()-1] == 'o' || words[i][words[i].length()-1] == 'u'));
        }
        vector<int> ans;
        for(auto& query : queries) {
            ans.push_back(pre[query[1] + 1] - pre[query[0]]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> a({"aba","bcb","ece","aa","e"});
    auto b = make_2_vector({{0,2},{1,4},{1,1}});
    print_vector(solution.vowelStrings(a, b));

    return 0;
}