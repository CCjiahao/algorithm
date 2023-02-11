#include <bits/stdc++.h>
using namespace std;

int cur_wei(int value, int wei) {
    while(wei--) value /= 10;
    if(value) return value % 10;
    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        if(n % 2 == 0) cout << n / 2 << " " << n / 2 << endl;
        else {
            int a = n / 2, b = n / 2 + 1;
            for(int i = 0; ; i++) {
                int cur = cur_wei(a, i);
                if(cur == -1 || cur != 9) break;
                a -= (4 + (i&1)) * (int)pow(10, i);
                b += (4 + (i&1)) * (int)pow(10, i);
            }
            cout << a << " " << b << endl;
        }
    }
    return 0;
}