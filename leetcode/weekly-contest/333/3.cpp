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

typedef long long ll;
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const ll mod = 1e9 + 7;
        vector<ll> pri({2, 3, 5, 7, 11, 13, 17, 19, 23, 29});
        vector<ll> mp(1024, 0);
        mp[0] = 1;
                
        auto check = [&](ll x) {
            for(auto& p : pri) {
                if(x % p == 0 && x % (p * p) == 0) return false;
            }
            return true;
        };

        for(auto& num : nums) {
            if(!check(num)) continue;
            int ans = 0;
            for(auto& p : pri) {
                ans <<= 1;
                if(num % p == 0 && num % (p*p) != 0) ans = ans + 1;
            }
            for(int i = 1023; i >= 0; i--) {
                if((i&ans) == ans) mp[i] = (mp[i] + mp[i ^ ans]) % mod;
            }
        }

        ll ans = 0;
        for(auto p : mp) ans += p;
        ans = (ans + mod - 1) % mod;
        return ans;
    }
};

int main() {
    Solution solution;
    auto a = vector<int>({11,2,19,7,9,27});
    solution.squareFreeSubsets(a);


    return 0;
}