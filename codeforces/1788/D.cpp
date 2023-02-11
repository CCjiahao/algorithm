#include <bits/stdc++.h>
using namespace std;

int a[3010];
const int mod = 1e9 + 7;
int mi[3010];

int main() {
    int n; cin >> n;
    mi[0] = 1;
    for(int i = 1; i <= n; i++) mi[i] = (mi[i - 1] * 2LL) % mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0, a[n + 1] = 2147483647;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        int left = i, right = i + 1;
        for(int j = i + 1; j <= n; j++) {
            while(left > 0 && a[i] - a[left] <= a[j] - a[i]) left--;
            while(right <= n && a[right] - a[j] < a[j] - a[i]) right++;
            ans = (ans + mi[n - (right - left - 1)]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}