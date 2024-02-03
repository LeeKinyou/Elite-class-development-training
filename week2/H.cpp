#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, ans, liar, arr[110];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        ans = -1;
        for (int i = 0; i <= 100; i++) {
            liar = 0;
            for (int j = 1; j <= n; j++) {
                if (arr[j] > i) 
                    liar++;
            }
            if (liar == i) {
                ans = liar;
                break;
            }   
        }
        if (ans == -1) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}