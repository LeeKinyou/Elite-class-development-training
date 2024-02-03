#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, arr[1010];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int ans = 0x7f7f7f7f, fl = 0;
        for (int i = 2; i <= n; i++) {  
            if (arr[i] - arr[i - 1] < 0) {
                fl = 1;
                break;
            }
            ans = min(ans, arr[i] - arr[i - 1]);
        }
        if (fl) {
            cout << "0" << endl;
        } else {
            cout << ans / 2 + 1 << endl;
        }
    }
    return 0;
}
/*
1 1
2 2
3 2
4 3
5 3
6 4
7 4
8 5
9 5
*/