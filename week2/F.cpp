#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long t, n, k, x, q, pos, ans, arr[2000010];
long long getans(long long len) {
    return (len - k + 2) * (len - k + 1) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> k >> q;
        pos = 0;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x > q) {
                if (i - pos - 1 >= k)
                    ans += getans(i - pos - 1);
                pos = i;
                // cout << i << " " << ans << endl;
            }
            
        }
        
        // cout << n - pos << " ";
        if (n- pos >= k)
            ans += getans(n - pos);
        cout << ans << endl;
    }
    return 0;
}