#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, k, ans, fl, f[100];
int main() {
    // ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k > 30) {
            cout << "0" << endl;  
            continue;
        }
        f[k] = n;
        ans = 0;
        for (int i = n; i; i--) {
            f[k - 1] = i;
            fl = 1;
            for (int j = k - 2; j >= 1; j--) {
                f[j] = f[j + 2] - f[j + 1];
                if (f[j] < 0) {
                    fl = 0;
                    break;
                }
            }
            if (fl && f[1] <= f[2]) {
                ans++;
                // for (int j = 1; j <= k; j++) {
                //     cout << f[j] << " ";
                // }
                // cout << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}