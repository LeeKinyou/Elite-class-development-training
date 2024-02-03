#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, k, ans, arr[100];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int pos = 0, min = 100;
        ans = 1;
        for (int i = 1; i <= n; i++) {
            if (arr[i] < min) {
                pos = i;
                min = arr[i];
            }
        }
        arr[pos] += 1;
        for (int i = 1; i <= n; i++) {
            ans *= arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}