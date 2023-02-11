#include <bits/stdc++.h>
using namespace std;

long long a[200010];
int dp[200010];

struct LS {
    int len;
    vector<long long> data;
    
    void push_back(long long value) {
        data.push_back(value);
    }

    int work() {
        sort(data.begin(), data.end());
        len = unique(data.begin(), data.end()) - data.begin();
        return len;
    }

    int quary(long long value) {
        return lower_bound(data.begin(), data.begin() + len, value) - data.begin();
    }
};

struct ArrayTree {
    int len;
    vector<int> data;
    ArrayTree(int len) {
        this->len = len;
        data = vector<int>(len + 10, -1e9 - 7);
    }

    int lowbit(int x) { return x & (-x); }

    void update(int x, int v) {
        while(x <= len) {
            data[x] = max(data[x], v);
            x += lowbit(x);
        }
    }

    int quary(int x) {
        int ans = -1e9-7;
        while(x > 0) {
            ans = max(ans, data[x]);
            x -= lowbit(x);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    LS ls;
    ls.push_back(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        ls.push_back(a[i]);
    }
    int len = ls.work();
    for(int i = 0; i <= n; i++) {
        a[i] = ls.quary(a[i]) + 1;
    }

    ArrayTree at(len);
    at.update(a[0], dp[0] = 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], at.quary(a[i]) + i);
        at.update(a[i], dp[i] - i);
    }
    cout << dp[n] << endl;
    return 0;
}