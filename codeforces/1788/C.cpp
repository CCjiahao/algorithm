#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        if(n % 2 != 1) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            int m = (n - 1) / 2;
            for(int i = 1; i <= m; i++) cout << i << " " << 3 * m + 2 + i << endl;
            for(int i = m + 1; i <= 2 * m + 1; i++) cout << i << " " << m + 1 + i << endl;
        }
    }
    return 0;
}