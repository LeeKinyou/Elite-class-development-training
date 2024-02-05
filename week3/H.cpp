#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n, ans, h[10010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    int l = 0, r = n;
    while (l < r) {
        ans += (h[l] - h[r]) * (h[l] - h[r]);
        l++;
        if (l == r) break;
        ans += (h[l] - h[r]) * (h[l] - h[r]);
        r--;
    } 
    cout << ans << endl;
    return 0;
}