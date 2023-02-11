#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int num = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 2) num++;
        }
        if(num & 1) cout << -1 << endl;
        else{
            int num2 = num / 2, now = 0;
            for(int i = 0; i < n - 1 && now <= num2; i++) {
                if(a[i] == 2) now++;
                if(now == num2) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}