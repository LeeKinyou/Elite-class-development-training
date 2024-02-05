#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, k, maxlen = 1e8, len[100010];
bool check(long long x) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += len[i] / x;
    }
    if (cnt >= k) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> len[i];
    }
    long long l = 0, r = maxlen;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(r < 1) cout << "0" << endl;
    else cout << l - 1 << endl;
    return 0;
}